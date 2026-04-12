#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m=0,ans=0;
    cin >> n;
    vector <int> h(n);
    rep(i,n){
        cin >> h[i];
        if(m<=h[i]){
            ++ans;
            m=h[i];
        }
    }

    cout << ans << endl;
    
    

    return 0;
}