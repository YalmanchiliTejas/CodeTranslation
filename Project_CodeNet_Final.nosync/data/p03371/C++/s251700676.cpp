#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll res,ans=a*x+b*y;
    for (int k=0; k<=2*max(x,y); k+=2) {
        int i=x-k/2;
        int j=y-k/2;
        i=max(i,0),j=max(j,0);
        res=a*i+b*j+c*k;
        ans=min(res,ans);
    }
    cout<<ans<<endl;
}   
