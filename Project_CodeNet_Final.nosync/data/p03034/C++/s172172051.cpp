#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main () {
    int N;
    cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    //c = A - B
    for(ll c = 1; c < N; c++) {
        ll sc = 0;
        set<ll> st;
        for(ll x = 0; x < 100000000; x++) {
            if(x * c >= N) break;
            ll A = N - 1 - x * c;
            ll B = A - c;
            if(A <= 0 || B <= 0) continue;



            if(st.find(x * c) != st.end() || st.find(N - 1 - x * c) != st.end() || x * c == N - 1 - x * c) {
                break;
            } else {
                st.insert(x * c);
                st.insert(N - 1 - x * c);
                sc += a[x * c];
                sc += a[(N - 1) - x * c];
                ans = max(ans, sc);
            }
        }
    }

    cout << ans << endl;
    return 0;
}