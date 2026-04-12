#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;



int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int maxh = 0;
    int ans = 0;
    rep(i,n){
        if (h[i] >= maxh) {
            ans++;
            maxh = max(maxh , h[i]);
        }
    }
    cout << ans << endl;
    
}

