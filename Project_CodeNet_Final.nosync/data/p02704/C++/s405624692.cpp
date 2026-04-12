#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int n;
vector <vector<vector<ll> > > res(64);
vector <ull> S,T,U,V;
bool have0h[505];
bool have0l[505];
bool have1h[505];
bool have1l[505];

pair<bool,bool> solvesingle(int a,int b)
{
	if(a==0 && b==1 || a==1 && b==0) return {false,false};
	int v;
	if(a!=-1) v=a;
	if(b!=-1) v=b;
	return {true,v};
}

pair<bool,vector<vector<bool> > > solve11(vector <int> h,vector <int> l)
{
	pair<bool,bool> o=solvesingle(h[0],l[0]);
	return {o.first,{{o.second}}};
}

pair<bool,vector<vector<bool> > > solve1m(vector <int> h,vector <int> l)
{
	int m=l.size();
	vector <bool> v;
	bool sa=false;
	if(h[0]==-1) sa=true;
	for(int i=0;i<m;i++)
	{
		if(l[i]==-1 || l[i]==h[0])
		{
			v.push_back(h[0]);
			sa=true;
		}
		else
		{
			v.push_back(l[i]);
		}
	}
	if(sa==false) return {false,{{}}};
	for(int i=0;i<m;i++)
	{
		if(v[i]==-1) v[i]=0;
	}
//	cout<<l[0]<<' '<<l[1]<<' '<<h[0]<<endl;
	return {true,{v}};
}

using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
pair<bool,vector<vector<bool> > > solven1(vector <int> h,vector <int> l)
{
	pair<bool,vector<vector<bool> > > o=solve1m(l,h);
	if(o.first==false) return {false,{{}}};
	else return mp(true,~o.second);
}

pair<bool,vector<vector<bool> > > solvenm(vector <int> h,vector <int> l)
{
	int n=h.size();
	int m=l.size();
	vector <vector<bool> > res(n);
	for(int i=0;i<n;i++)
	{
		res[i].resize(m);
	}
	for(int i=0;i<n;i++)
	{
		res[i][i%m]=1;
	}
	for(int j=0;j<m;j++)
	{
		res[j%n][j]=1;
	}
	return mp(true,res);
}

pair<bool,vector<vector<bool> > > solve(vector <int> h,vector <int> l)
{
	int n=h.size();
	int m=l.size();
	if(n==0 || m==0)
	{
		bool ok=true;
		for(auto &x:h) ok&=(x==-1);
		for(auto &y:l) ok&=(y==-1);
		return {ok,{{}}};
	}
	if(n==1 && m==1) return solve11(h,l);
	if(n==1) return solve1m(h,l);
	if(m==1) return solven1(h,l);
	return solvenm(h,l);
}

inline bool getbit(ull mask,int k)
{
	return ((1uLL<<k) & mask);
}

inline void paint(int x,int y,int color)
{
	if(color==0) have0h[x]=true,have0l[y]=true;
	if(color==1) have1h[x]=true,have1l[y]=true;
}

pair<bool,vector<vector<ll> > > solve(int k)
{
	memset(have0h,0,sizeof(have0h));
	memset(have0l,0,sizeof(have0l));
	memset(have1h,0,sizeof(have1h));
	memset(have1l,0,sizeof(have1l));
	vector <vector<ll> > a(n,vector <ll> (n,-1));
	vector <int> h,l;
	vector <int> idh,idl;
	for(int i=0;i<n;i++)
	{
		if(S[i]==0 && getbit(U[i],k))
		{
			for(int j=0;j<n;j++) paint(i,j,1);
		}
		if(S[i]==1 && !getbit(U[i],k))
		{
			for(int j=0;j<n;j++) paint(i,j,0);
		}
	}
	for(int j=0;j<n;j++)
	{
		if(T[j]==0 && getbit(V[j],k))
		{
			for(int i=0;i<n;i++)
			{
				paint(i,j,1);
			}
		}
		if(T[j]==1 && !getbit(V[j],k))
		{
			for(int i=0;i<n;i++)
			{
				paint(i,j,0);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(S[i]==0 && !getbit(U[i],k)) h.push_back(have0h[i]?-1:0),idh.push_back(i);
		if(S[i]==1 && getbit(U[i],k)) h.push_back(have1h[i]?-1:1),idh.push_back(i);
	}
	for(int j=0;j<n;j++)
	{
		if(T[j]==0 && !getbit(V[j],k)) l.push_back(have0l[j]?-1:0),idl.push_back(j);
		if(T[j]==1 && getbit(V[j],k)) l.push_back(have1l[j]?-1:1),idl.push_back(j);
	}
	pair<bool,vector <vector<bool> > > o=solve(h,l);
	if(o.first==false) return mp(false,a);
	vector <vector<bool> > &v=o.second;
	for(int i=0;i<n;i++)
	{
		if(S[i]==0 && getbit(U[i],k))
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]!=0) a[i][j]=1;else return mp(false,a);
			}
		}
		if(S[i]==1 && !getbit(U[i],k))
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]!=1) a[i][j]=0;else return mp(false,a);
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		if(T[j]==0 && getbit(V[j],k))
		{
			for(int i=0;i<n;i++)
			{
				if(a[i][j]!=0) a[i][j]=1;else return mp(false,a);
			}
		}
		if(T[j]==1 && !getbit(V[j],k))
		{
			for(int i=0;i<n;i++)
			{
				if(a[i][j]!=1) a[i][j]=0;else return mp(false,a);
			}
		}
	}
	for(int i=0;i<h.size();i++)
	{
		for(int j=0;j<l.size();j++)
		{
			a[idh[i]][idl[j]]=v[i][j];
		}
	}
	return mp(true,a);
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	quickcin;
	cin>>n;
	S.resize(n);
	T.resize(n);
	U.resize(n);
	V.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>S[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>T[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>U[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>V[i];
	}
	for(int i=0;i<64;i++)
	{
		pair<bool,vector<vector<ll> > > o=solve(i);
		if(o.first==false) over(-1);
		res[i]=o.second;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			unsigned ll t=0;
			for(int k=0;k<64;k++)
			{
				t|=((unsigned long long)res[k][i][j]<<k);
			}
			cout<<t<<' ';
		}
		cout<<endl;
	}
	return 0;
}

/*
2
1 1
0 0
1 1
0 1
*/