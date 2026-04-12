#include <bits/stdc++.h>
using namespace std;
 
 
#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;
 
ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;
 
int main(){
    int n;
    cin >> n;
    int mh = 0;
    int ans = 0;
    rp(i, 0, n){
        int h;
        cin >> h;
        if(h >= mh){
            ans ++;
            mh = h;
        }
    }
    cout << ans << endl;
    return 0;
}
