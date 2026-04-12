#include<iostream>
#include<algorithm>
using namespace std;

void printc(char c,int n)
{
	for(int i=0;i<n;i++)cout << c;
	return;
}

int main()
{
	int n;
	string S;
	int al[55][26]={};
	int tmp;
	
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cin >> S;
		for(int j=0;j<S.size();j++)
		{
			al[i][S[j]-'a']++;
		}
	}
	
	for(int i=0;i<26;i++)
	{
		tmp=1e3;
		for(int j=0;j<n;j++)
			tmp=min(tmp,al[j][i]);
		printc(i+'a',tmp);
	}
	cout << endl;
	return 0;
}
