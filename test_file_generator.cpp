#include<bits/stdc++.h> 
using namespace std;
string char_to_str(char c){string tem(1,c);return tem;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>//usage rand<long long>()
T rand() {
    return uniform_int_distribution<T>()(rng);
}
/*
output format of the test file 
number of pages in the primary memory 		number of pages in the secondary memory 
number of entries in the sequence of pages (N)
N lines with single integers 
*/
int main()
{
	string file_name="";
	cout<<"Enter the name of the test file to be generated : "<<endl;
	cin>>file_name;
	char f_name[file_name.length()];
	for(int i=0;i<file_name.length();++i)
	{
		f_name[i]=file_name[i];
	}
	int number_of_pages_in_primary_memory;
	int number_of_pages_in_secondary_memory;
	int number_of_entries;
	cout<<"Enter number of pages in primary memory : ";
	cin>>number_of_pages_in_primary_memory;
	cout<<"Enter number of pages in secondary memory : ";
	cin>>number_of_pages_in_secondary_memory;
	cout<<"Enter number of entries : ";
	cin>>number_of_entries;
	freopen(f_name,"w",stdout);
	cout<<number_of_pages_in_primary_memory<<" "<<number_of_pages_in_secondary_memory<<"\n";
	cout<<number_of_entries<<"\n";
	for(int i=0;i<number_of_entries;++i)
	{
		cout<<((rand<int>()))%number_of_pages_in_secondary_memory + 1<<"\n";
	}
}