#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){
    int a,b,c,x,y,ans=inf;cin>>a>>b>>c>>x>>y;
    for(int i=0;i<=2*max(x,y);i+=2){
        int k=x-i/2,j=y-i/2;
        if(k<0) k=0;if(j<0) j=0;
        ans=min(ans,a*k+b*j+c*i);
    }
    cout<<ans<<endl;
}