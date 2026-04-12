/*
      author  : nishi5451
      created : 15.08.2020 00:28:35
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int ans = 0;
    int now = 0;
    rep(i,n){
        int h;
        cin >> h;
        if(h >= now) ans++;
        now = max(now,h);
    }
    cout << ans << endl;
    return 0;
}