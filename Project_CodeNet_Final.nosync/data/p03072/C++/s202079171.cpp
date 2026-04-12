#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) (x).begin(),(x).end()
#define dup(x,y) (((x)+(y)-1)/(y))
#define sz(x) (int)(x).size()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int max = 0;
    int ans = 0;
    rep(i,n){
        if(max <= h[i]){
            max = h[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}