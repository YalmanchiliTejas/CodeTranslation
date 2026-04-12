#include <bits/stdc++.h>
#define R cin>>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int N; R N;
    int a[N];
    rep(i, N) R a[i];
    int max = 0, cnt = 0;
    rep(i, N) {
        if (max <= a[i]) {
            max = a[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}
