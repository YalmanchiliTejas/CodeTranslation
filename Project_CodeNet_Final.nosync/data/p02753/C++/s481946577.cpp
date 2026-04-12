#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef queue<char> qc;
typedef queue<string> qs;
typedef vector<char> vc;
typedef vector<string> vs;
typedef map<char,int> mpci;
typedef map<int,int> mpii;
typedef map<string,int> mpsi;
typedef set<int> sei;
typedef set<char> sec;
typedef set<string> ses;
typedef stack<ll> si;
typedef stack<char> sc;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pll> vpll;
typedef vector<pdd> vdd;
typedef unsigned int uint;
typedef long double ld;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;
/*=====================================================================*/
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define all(s) (s).begin(),(s).end()
#define fi first
#define se second
#define be begin
#define en end
#define m_p make_pair
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define forn(i,p,n) for(int i=p;i<=n;i++)
#define ford(i,p,n) for(int i=n;i>=p;i--)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define zero(a) memset(a,0,sizeof(a))
#define number(a,num) memeset(a,num,sizeof(a))

/*=====================================================================*/

inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
inline void write(long long x) {
  static long long sta[35];
  long long top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
  puts("");
}
void finish(string s)
{
	cout<<s<<endl;
	exit(0);
}
/*======================================================================*/
bool prime(int n)
{
	if(n==0||n==1)
	  return false;
	for(int i=2;i*i<=n;i++)
	  if(n%i==0)
	    return false;
	return true;
}
const ll power(int n,int k)
{
	ll t=1;
	rep(i,k)
	  t*=n;
	return t;
}
const string turn2(int n)
{
	string s="";
	while(n!=0)
	{
		s+=(char)(n%2+'0');
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
string turn(int n,int k)
{
	string s="";
	while(n)
	{
		s+=(char)(n%k+'0');
		n/=k;
	}
	reverse(s.begin(),s.end());
	return s;
}
const string turn16(int n)
{
	string s="";
	while(n!=0)
	{
		if(n%16>9)
		  s+=(char)('A'+n%16-10);
		else
		  s+=(char)('0'+n%16);
		n/=16;
	}
	reverse(s.begin(),s.end());
	return s;
}
const ll quickpower(int n,int k)
{
	if(k==1)
	  return n;
	if(k%2==1)
	  return n*quickpower(n,k/2)*quickpower(n,k/2);
	else
	  return quickpower(n,k/2)*(quickpower(n,k/2));
}
/*
void merge(int a[],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++)
	{
	  l[i]=a[i+left];
    }
	for(int i=0;i<n2;i++)
	{
	  r[i]=a[mid+i];
	}
	r[n2]=l[n1]=INF;
	int i=0;
	int j=0;
	for(int k=left;k<right;k++)
	{
		if(l[i]<=r[j])
		{
			a[k]=l[i++];
		}
		else
		{
			a[k]=r[j++];
		}
	}
}
void mergesort(int a[],int left,int right)
{
	if(left+1<right)
	{
		int mid=(left+right)/2;
		mergesort(a,left,mid);
		mergesort(a,mid,right);
		merge(a,left,mid,right);
	}
}
int binsearch(int x,int v[],int n)
{
	int low=0,high=n-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x<v[mid])
		  high=mid-1;
		else
		  if(x>v[mid])
		    low=mid+1;
		  else
		    return mid+1;
	}
	return -1;
}
int partition(int a[],int left,int right)
{
	int p=a[left];
	int i=left;
	int j=right+1;
	for(;;)
	{
		while(a[++i]<p)
		  if(i>=right)
		    break;
		while(a[j--]>p)
		  if(j<=left)
		    break;
		if(i>=j)
		  break;
		else
		  swap(a[i],a[j]);
	}
	if(j>=left)
	  return j;
	swap(a[left],a[j]);
	return j;
}
void quicksort(int a[],int left,int right)
{
	int q;
	while(right>left)
	{
		q=partition(a,left,right);
	    if(n-q+1==k)
	    {
	        cout<<a[q];
	  		exit(0);
		}
		quicksort(a,left,q-1);
		quicksort(a,q+1,right);
	}
}
void dfs(int n)
{
	if(use[n])
	  return;
	use[n]=true;
	cout<<n<<endl;
	for(int i=0;i<v[n].size();i++)
	  dfs(v[n][i]);
}*/
/*======================================================================*/
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
/*======================================================================*/
int main()
{
  /*
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  */
  /*====================================================================*/
  string s;
  int a0=0,a1=0;
  cin>>s;
  rep(i,3)
  {
  	if(s[i]=='A')
  	  a0++;
  	else
  	  a1++;
  }
  if(!a0||!a1)
    finish("No");
  finish("Yes");
  return 0;
}
