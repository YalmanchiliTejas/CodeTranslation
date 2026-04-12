#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define repd(i,a,b) for (int i=(a);i<(b);i++)
typedef long long ll;
using namespace std;

int main() {
    int n;cin >> n;
    int H[n];
    rep(i,n) cin >> H[i];
    int max = H[0];
    int ans = 0;
    repd(i,1,n){
        if(H[i]>=max){
            max = H[i];
            ans++;
        }
    }
    cout << ans + 1 << endl;
}