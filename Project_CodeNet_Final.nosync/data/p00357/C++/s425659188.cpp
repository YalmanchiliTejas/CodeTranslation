#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define F first
#define S second
#define mod 1000000007
#define INF 9000000000000000000
signed main(void){
    int n;cin>>n;
    vector<int>V(n);
    rep(i,n){
        cin>>V[i];
    }
    bool ans=true;
    int ma=0;
    rep(i,n){
        if(i>ma)break;
        ma=max(ma,V[i]/10+i);
    }
    if(ma<n-1)ans=false;
    reverse(all(V));
    ma=0;
    rep(i,n){
        if(i>ma)break;
        ma=max(ma,V[i]/10+i);
    }
    if(ma<n-1)ans=false;
    if(ans)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
