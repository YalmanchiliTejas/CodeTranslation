#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int dekai=0;
    int cnt=0;
    rep(i,n){
        if(h[i]>dekai){
            cnt++;
            dekai = h[i];
        }
        else if(h[i] == dekai) cnt++;
    }
    cout << cnt << endl;
}