#include <bits/stdc++.h> 
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define maxnkp make_pair
#define fi first
#define se second
#define eps 1e-6
using namespace std;
typedef long long ll;
const int mods = 998244353;
const int maxn = 2e3+10;

ll n,k;

inline long long read() {
    long long tmp=0, fh=1; char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
    while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
    return tmp*fh;
}

int main() {
	cin>>n>>k;
	if(k!=n) cout<<"No"<<endl;
	else cout<<"Yes"<<endl; 
}