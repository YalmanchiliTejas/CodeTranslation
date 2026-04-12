#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
    ll x=0,f=1; char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())
        if(ch=='-')f=-f;
    for(;ch>='0'&&ch<='9';ch=getchar())
        x=x*10+ch-'0';
    return x*f;
}
inline void chkmin( int &a,int b ) { if(a>b) a=b; }
inline void chkmax( int &a,int b ) { if(a<b) a=b; }
#define _ read()
int main() {
	int n=_,mx=0,ans=0;
	for( int i=1;i<=n;i++ ) {
		int x=_; chkmax(mx,x);
		ans+=(x==mx);
	}cout<<ans;
}