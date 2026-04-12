#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    REP(i, n) cin >> h[i];
    int ans = 1;

    for (int i = 1; i < n; i++){
        bool ok = true;
        for (int j = 0; j < i; j++){
            if (h[j] > h[i]){
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << "\n";
}
