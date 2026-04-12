#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int x,y,z;cin>>x>>y>>z;
    int ans=0;
    x-=z;
    while(1){
        x-=y;
        if(x>=z){
            x-=z;
            ans++;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
}