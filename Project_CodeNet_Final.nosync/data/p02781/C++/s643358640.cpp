#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
int N,K,A[MAXN];char s[MAXN];
int main()
{
	scanf("%s",s+1);
	N=strlen(s+1);
	cin>>K;
	for (int i=1;i<=N;++i) A[i]=s[i]-'0';
	long long Ans=0;
	if (K==1)
	{
		Ans+=A[1];
		for (int i=2;i<=N;++i) Ans+=9;
	}
	else if (K==2)
	{
		Ans+=(A[1]-1)*(N-1)*9;
		int p=-1;
		for (int i=2;i<=N;++i) if (A[i]) {p=i;break;}
		if (p!=-1)
		{
			Ans+=A[p];
			for (int i=p+1;i<=N;++i) Ans+=9;
		}
		for (int i=2;i<=N;++i)
			for (int j=i+1;j<=N;++j)
				Ans+=9*9;
	}
	else
	{
		Ans+=(A[1]-1)*((N-1)*(N-2)/2)*9*9;
		int p=-1;
		for (int i=2;i<=N;++i) if (A[i]) {p=i;break;}
		if (p!=-1)
		{
			Ans+=(A[p]-1)*(N-p)*9;
			int pp=-1;
			for (int i=p+1;i<=N;++i) if (A[i]) {pp=i;break;}
			if (pp!=-1)
			{
				Ans+=A[pp];
				for (int i=pp+1;i<=N;++i) Ans+=9;
			}
			for (int i=p+1;i<=N;++i)
				for (int j=i+1;j<=N;++j)
					Ans+=9*9;
		}
		for (int i=2;i<=N;++i)
			for (int j=i+1;j<=N;++j)
				for (int k=j+1;k<=N;++k)
					Ans+=9*9*9;
	}
	cout<<Ans<<endl;
	return 0;
}