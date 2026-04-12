#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()


int main(){
    int n; cin>>n;
    int h[n];
    rep(i,0,n) cin>>h[i];
    int H=h[0];
    int ans=1;
    rep(i,1,n){
        if(h[i]>=H){
            ans++;
            H=h[i];
        }
    }
    cout<<ans<<endl;
}