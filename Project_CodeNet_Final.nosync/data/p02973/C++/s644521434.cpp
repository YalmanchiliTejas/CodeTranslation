#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<vector>
#define inf 2147483647
#define rep(i,a,b) for(int i=a;i<b;i++)
#define  rr read()
#define ll long long
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define CloseIo   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int read()
{
    char ch = getchar();
	int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
const int mod=1e9+7;
const int N=1e5+5;
ll a[N];
int main()
{
	ll n;
	CloseIo;
	cin>>n;
	multiset<ll>s;
	rep(i,0,n)
	{
		 ll t;
		 cin>>t;
		 multiset<ll>::iterator it=s.lower_bound(t);
		 if(it==s.begin())
		 s.insert(t);
		 else
		 {
		 	 it--;
		 	 s.erase(it);
		 	 s.insert(t);
		 }
	}
	cout<<s.size();
}
