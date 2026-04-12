#include<bits/stdc++.h>
#define MAXN 100000+10

using namespace std;

long long n;
long long MOD;
long long Ans[MAXN];
long long S[MAXN];

int main()
{
	long long Now;
	cin>>n>>Now>>MOD;
	memset(Ans,-1,sizeof(Ans));
	Ans[Now] = 1;
	S[1] = Now;
	//long long Count = Now;
	for(int i=2;i<=n;i++)
	{
		Now = Now*Now%MOD;
		S[i] = S[i-1] + Now;
		if(Ans[Now]!=-1)
		{
			long long Re = S[Ans[Now]-1];
			long long XHJ = S[i] - S[Ans[Now]];
			long long CD = i - Ans[Now];
			n -= Ans[Now] - 1;
			Re += XHJ * (n/CD);
			Re += S[Ans[Now]+n%CD-1] - S[Ans[Now]-1];
			cout<<Re;
			return 0;
		}
		Ans[Now] = i;
	}
	cout<<S[n];
	return 0;
}
