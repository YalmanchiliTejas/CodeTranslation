/**
	������������ Author : Avi J Patel ������������
	������������ University : DA-IICT ������������
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define N 100000
#define ff first
#define ss second
#define si size()
#define MOD 1000000007
#define large 10000000000000001

#define For(i,m,n) for(long long i=m;i<n;i++)
#define st(x) sort(x.begin(),x.end())
#define re(x,i) reverse(x.begin()+i,x.end())
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
/*void calc()
{
	for(int i=0;i<2005;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
		for(int j=1;j<i;j++)
		{
			a[i][j]=(a[i-1][j-1]+a[i-1][j])%MOD;	
		}
	}
}*/
int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);
	int temp=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//vector<ll> t;
	int cnt=0;
	multiset<ll> b;
	for(int i=0;i<n;i++)
	{
		auto it=b.lower_bound(a[i]);
		if(it==b.begin())
		{
			cnt++;
		}
		else
		{
			it--;
			b.erase(it);
		}
		b.insert(a[i]);
	}
	cout<<cnt;
	return 0;
}







