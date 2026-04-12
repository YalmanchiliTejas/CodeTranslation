#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ll n, x, m;    cin >> n >> x >> m;
    vector<ll> v;   ll f, g = -1;
    set<ll> st;
    int k = 0;
    for (ll y = x; k < min(m+1, n); k++) {
        //cout << y << " ";
        if (st.find(y) != st.end()) {
            f = y;
            g = k;
            break;
        }
        
        st.insert(y);
        v.push_back(y);
        y = (y * y) % m;
    }
    //cout << endl << g << endl;

    if (g == -1) {
        ll ans = 0, y = x;
        for (int i = 0; i < n; i++) {
            ans += y;
            y = y*y % m;
        }
        cout << ans << endl;
        return 0;
    }

    int j;
    for (int i = 0; i < v.size(); i++) {
        if (f == v[i]) {
            j = i;
            break;
        }
    }
    //cout << j << endl;
    
    ll ans = 0 ,l = g-j;
    //cout << endl; 
    for (ll i = 0; i < v.size(); i++) {
        if (i < j) {
            ans += v[i];
        }
        else {
            //cout << v[i] << " " << (n-1-i)/l + 1 << endl;
            //cout << v[i] * ((n-1-i)/l + 1) << endl;
            ans += v[i] * ((n-1-i)/l + 1);
        }
    }
    cout << ans << endl;
    return 0;
}

//小数点精度
//cout << fixed << std::setprecision(15) << y << endl;