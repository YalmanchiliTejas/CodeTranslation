//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int a[2000*3+5];
//int dp1[2005][2005];//Õý³£µÄ´øÁ½¸ö 
//int dp2[2005];//´øxµÄ×î´óÖµ 
//int dp3;//È«²¿µÄ×î´óÖµ 
//int k;
//int r[3];
//int tn;
//
//struct Info
//{
//	int x;
//	int y;
//	int v;
//	Info(int _x,int _y,int _z)
//	{
//		x=_x;
//		y=_y;
//		v=_z;
//	}
//	Info(){}
//};
//
//vector <Info> updates;
//
//inline int get(int n,int pos)
//{
//	return a[n*3-2+pos];
//}
//
//inline void update()
//{
//	int x=1,y=2,v=3;
//	for(auto info:updates)
//	{
//		x=info.x;
//		y=info.y;
//		v=info.v;
//		chmax(dp1[x][y],v);
//		chmax(dp1[y][x],v);
//		chmax(dp2[x],v);
//		chmax(dp2[y],v);
//		chmax(dp3,v);
//	}
//	updates.clear();
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n;
//	tn=n;
//	n*=3;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//		a[i]--;
//	}
//	reverse(a,a+n);
//	k=1;
//	int s=0;
//	for(int i=1;i+3<n;i+=3)
//	{
//		if(a[i]==a[i+1] && a[i+1]==a[i+2])
//		{
//			s++;
//			continue;
//		}
//		a[k++]=a[i];
//		a[k++]=a[i+1];
//		a[k++]=a[i+2];
//	}
//	a[k++]=a[n-2];
//	a[k++]=a[n-1];
//	int res=0;
//	k/=3;
//	for(int i=0;i<tn;i++)
//	{
//		for(int j=0;j<tn;j++)
//		{
//			dp1[i][j]=-inf;
//		}
//		dp2[i]=-inf;
//	}
//	dp3=-inf;
////	memset(dp1,-1,sizeof(dp1));
////	memset(dp2,-1,sizeof(dp2));
////	dp3=-1;
//	updates.push_back({a[n-1],a[n-2],0});
//	update();
//	for(int i=k-1;i>0;i--)
//	{
//		r[0]=get(i,0);
//		r[1]=get(i,1);
//		r[2]=get(i,2);
//		for(int it=0;it<3;it++)
//		{
//			updates.push_back({r[0],r[1],dp1[r[2]][r[2]]+1});
//			updates.push_back({r[0],r[1],dp3});
//			for(int j=0;j<tn;j++)
//			{
//				updates.push_back({r[0],j,dp2[j]});
//				if(r[1]==r[2]) updates.push_back({r[0],j,dp1[r[1]][j]+1});
//			}
//			swap(r[0],r[1]);
//			swap(r[1],r[2]);
//		}
//		update();
//	}
//	for(int i=0;i<tn;i++)
//	{
//		for(int j=0;j<tn;j++)
//		{
//			chmax(res,dp1[i][j]+(i==j && a[0]==i));
//		}
//	}
//	cout<<res+s<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
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
ostream & operator << (ostream & cout,set <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
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
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
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
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
using namespace std;
int n;
int a[2000*3+5];
int dp1[2005][2005];//Õý³£µÄ´øÁ½¸ö 
int dp2[2005];//´øxµÄ×î´óÖµ 
int dp3;//È«²¿µÄ×î´óÖµ 
int k;
int r[3];
int tn;

struct Info
{
	int x;
	int y;
	int v;
	Info(int _x,int _y,int _z)
	{
		x=_x;
		y=_y;
		v=_z;
	}
	Info(){}
};

vector <Info> updates;

inline int get(int n,int pos)
{
	return a[n*3-2+pos];
}

inline void update()
{
	int x=1,y=2,v=3;
	for(auto info:updates)
	{
		x=info.x;
		y=info.y;
		v=info.v;
		chmax(dp1[x][y],v);
		chmax(dp1[y][x],v);
		chmax(dp2[x],v);
		chmax(dp2[y],v);
		chmax(dp3,v);
	}
	updates.clear();
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	tn=n;
	n*=3;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	reverse(a,a+n);
	k=1;
	int s=0;
	for(int i=1;i+3<n;i+=3)
	{
		if(a[i]==a[i+1] && a[i+1]==a[i+2])
		{
			s++;
			continue;
		}
		a[k++]=a[i];
		a[k++]=a[i+1];
		a[k++]=a[i+2];
	}
	a[k++]=a[n-2];
	a[k++]=a[n-1];
	int res=0;
	k/=3;
	for(int i=0;i<tn;i++)
	{
		for(int j=0;j<tn;j++)
		{
			dp1[i][j]=-inf;
		}
		dp2[i]=-inf;
	}
	dp3=-inf;
//	memset(dp1,-1,sizeof(dp1));
//	memset(dp2,-1,sizeof(dp2));
//	dp3=-1;
	updates.push_back({a[n-1],a[n-2],0});
	update();
	for(int i=k-1;i>0;i--)
	{
		r[0]=get(i,0);
		r[1]=get(i,1);
		r[2]=get(i,2);
		for(int it=0;it<3;it++)
		{
			updates.push_back({r[0],r[1],dp1[r[2]][r[2]]+1});
			updates.push_back({r[0],r[1],dp3});
			for(int j=0;j<tn;j++)
			{
				updates.push_back({r[0],j,dp2[j]});
				if(r[1]==r[2]) updates.push_back({r[0],j,dp1[r[1]][j]+1});
			}
			swap(r[0],r[1]);
			swap(r[1],r[2]);
		}
		update();
	}
	for(int i=0;i<tn;i++)
	{
		for(int j=0;j<tn;j++)
		{
			chmax(res,dp1[i][j]+(i==j && a[0]==i));
		}
	}
	cout<<res+s<<endl;
	return 0;
}
