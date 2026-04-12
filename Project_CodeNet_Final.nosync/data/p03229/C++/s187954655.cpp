#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


ll odd_cal(vector<ll> A,int N)
{
	ll num1=A[N/2-1]+A[N/2];
	rep(i,N/2-1)
	{
		num1+=A[i]*2;
	}
	ll num2=0;
	for(int i=N/2+1;i<N;i++)
	{
		num2+=A[i]*2;
	}
	return abs(num1-num2);
}

ll even_cal(vector<ll> A,int N)
{
	ll num1=A[N/2-1];
	rep(i,N/2-1)
	{
		num1+=A[i]*2;
	}
	ll num2=A[N/2];
	for(int i=N/2+1;i<N;i++)
	{
		num2+=A[i]*2;
	}
	return abs(num1-num2);
}
int main()
{
	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N)
	{
		cin>>A[i];
	}
	//odd
	if(N%2)
	{
		sort(A.begin(),A.end());
		ll res1=odd_cal(A,N);
		reverse(A.begin(),A.end());
		ll res2=odd_cal(A,N);
		cout<<max(res1,res2)<<endl;
	}
	//even
	else
	{
		sort(A.begin(),A.end());
		ll res1=even_cal(A,N);
		reverse(A.begin(),A.end());
		ll res2=even_cal(A,N);
		cout<<max(res1,res2)<<endl;
	}
	return 0;
}
