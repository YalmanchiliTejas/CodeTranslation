#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int cnt = 1, maxh;
    int n; cin >> n;
    vector<int> h(n); rep(i,n) cin >> h[i];

    maxh = h[0];

    for(int i = 1; i < n; i++){
        if(h[i] >= maxh){
            cnt++;
            maxh = h[i];
        }
    }

    put(cnt);
}