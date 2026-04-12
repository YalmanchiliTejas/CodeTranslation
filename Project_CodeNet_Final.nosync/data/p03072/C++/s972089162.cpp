#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    int high=0;
    int ans=0;
    rep(i,N){
        int h; cin>>h;
        if(high <= h){
            ans++;
            high = h;
        }
    }
    cout << ans << endl;
}
