#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define dev 998244353 //tenka1
#define P pair<int,int>
#define F first
#define S second

signed main(){
    int a,b,c,x,y,p,q;
    cin>>a>>b>>c>>x>>y;
    int base=a*x+b*y;
    int m=min(x,y);
    int n=max(x,y);
    if(a+b>c*2){
        if(x<y)p=c*2*m+b*(n-m);
        else p=c*2*m+a*(n-m);
        q=c*2*n;
        int ans=min(p,q);
        cout<<ans<<endl;
    }
    else cout<<base<<endl;
    return 0;
}
