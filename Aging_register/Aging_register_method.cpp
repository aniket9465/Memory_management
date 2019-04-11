#include<bits/stdc++.h> 
using namespace std;
/*
Output format for each input test file : 
number_of_pages_in_primary_memory number_of_pages_in_secondary_memory number_of_entries number_of_page_fault time
*/
int main()
{
	int n;
	cout<<"Enter number of input files : \n";
	cin>>n;
	string in_file[n],out_file;
	cout<<"Enter the input file names : \n";
	for(int i=0;i<n;++i)
		cin>>in_file[i];
	cout<<"Enter the output file name : \n";
	cin>>out_file;

	char out[out_file.length()];
	for(int i=0;i<out_file.length();++i)
	{
		out[i]=out_file[i];
	}
	freopen(out,"w",stdout);
	
	for(int j=0;j<n;++j)
	{
		auto start = chrono::high_resolution_clock::now();
		char in[in_file[j].length()];
		for(int i=0;i<in_file[j].length();++i)
		{
			in[i]=in_file[j][i];
		}
		ifstream fin;
		fin.open(in);
		int number_of_pages_in_primary_memory;
		int number_of_pages_in_secondary_memory;
		int number_of_entries;
		fin>>number_of_pages_in_primary_memory;
		fin>>number_of_pages_in_secondary_memory;
		fin>>number_of_entries;
		int number_of_page_fault = 0;
		int aging_register[number_of_pages_in_primary_memory+1][number_of_pages_in_primary_memory+1]={};
		int page_number[number_of_pages_in_primary_memory+1]={};
		for(int i=0;i<number_of_entries;++i)
		{
			int page;
			fin>>page;
			int fl=0,po=0;
			for(int k=1;k<=number_of_pages_in_primary_memory;++k)
			{
				if(page_number[k]==page)
				{
					fl=1;
					po=k;
					break;
				}
			}
			if(fl==1) // page found 
			{
				for(int k=1;k<=number_of_pages_in_primary_memory;++k)
					for(int l=number_of_pages_in_primary_memory;l>=1;--l)
						aging_register[k][l]=aging_register[k][l-1];
				aging_register[po][1]=1;
				continue;
			}
			// page fault
			++number_of_page_fault;
			//generated delay 
			int delay=10000;
			while(delay)
			{
				--delay;
			}
			po=0;
			long long v=INT_MAX;
			for(int l=1;l<=number_of_pages_in_primary_memory;++l){
				int val=0;
				for(int k=1;k<=number_of_pages_in_primary_memory;++k)
				{
					if(aging_register[l][k]==1)
						val+=(1ll<<(number_of_pages_in_primary_memory-k));
				}
				if(v>val){
					v=val;
					po=l;
				}
			}
			for(int k=1;k<=number_of_pages_in_primary_memory;++k)
				for(int l=number_of_pages_in_primary_memory;l>=1;--l)
					aging_register[k][l]=aging_register[k][l-1];
			for(int k=1;k<=number_of_pages_in_primary_memory;++k)
			{
				aging_register[po][k]=0;
			}
			page_number[po]=page;
			aging_register[po][1]=1;
		}
		fin.close();
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
		cout<<number_of_pages_in_primary_memory<<" "<<number_of_pages_in_secondary_memory<<" ";
		cout<<number_of_entries<<" "<<number_of_page_fault<<" "<<duration.count()<<" microseconds\n";
	}
}