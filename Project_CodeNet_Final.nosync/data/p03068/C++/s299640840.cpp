#include<bits/stdc++.h>
using namespace std;
int main()
{
	char S[1000];
	int N,K;
	cin>>N;
	cin>>S;
	cin>>K;
	K--;
	for(int i=0;i<N;i++)
	{
		if(S[i]==S[K])
		cout<<S[i];
		else
		cout<<"*";
	}
	return 0;
	
}