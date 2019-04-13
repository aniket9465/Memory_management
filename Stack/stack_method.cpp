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
		vector<int> stack;
		for(int i=1;i<=number_of_entries;++i)
		{
			int page;
			fin>>page;
			int fl=0;
			for(auto r:stack)
				if(r==page)
					fl=1;
			if(fl==1) // page found 
			{
				vector<int> temp;
				temp.push_back(page);
				for(int k=0;k<stack.size();++k)
				{
					if(stack[k]!=page)
						temp.push_back(stack[k]);
				}
				stack=temp;
				continue;
			}

			//page fault
			++number_of_page_fault;
			//generated delay 
			int delay=10000;
			while(delay)
			{
				--delay;
			}
			vector<int> temp;
			temp.push_back(page);
			for(int k=0;k<min(number_of_pages_in_primary_memory-1,(int)stack.size());++k)
			{
				temp.push_back(stack[k]);
			}
			stack=temp;
		}
		fin.close();
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
		cout<<number_of_pages_in_primary_memory<<" "<<number_of_pages_in_secondary_memory<<" ";
		cout<<number_of_entries<<" "<<number_of_page_fault<<" "<<duration.count()<<" microseconds\n";
	}
}