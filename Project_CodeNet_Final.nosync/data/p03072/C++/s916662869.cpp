#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    int n;
    cin >> n;

    vector<int> h(n);
    rep(i,n)cin >> h[i];
    int ans=0;
    rep(i,n){
        bool f=true;
        rep(j,i){
            if(h[j]>h[i]){
                f=false;
            }
        }
        if(f){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}