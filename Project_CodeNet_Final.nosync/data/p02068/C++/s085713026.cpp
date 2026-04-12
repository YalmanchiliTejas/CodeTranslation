#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i=(int)(a);i<(int)(b);++i)

long N;
vector<long> A;
unordered_map<int,int> mp;
void solve(){
    rep(i, N) {
        int a = A[i];
        int k = 2;
        while((k * k) < a) {
            if (a % k == 0) {
                mp[k]++;
                a /= k;
            }
            else {
                k++;
            }
        }
        if (a > 1) mp[a]++;

    }
    long ans = 0;
    for(auto itr = mp.begin(); itr != mp.end();itr++) {
        long sum = 0;
        int key = itr->first;
        rep(i, N) {
            if (A[i] % key == 0) {
                sum += (long) A[i];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A = vector<long>(N);
    rep(i, N) {
        cin >> A[i];
    }
    
    solve();

    
    return 0;
}
