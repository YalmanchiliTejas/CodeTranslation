#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
using namespace std;



int main() {
//    cout << setprecision(100);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    map<int, int> d;
    d[a[0]] = 1;

    for (int i = 1; i < n; i++) {
        auto it = d.lower_bound(a[i]);
        if (it != d.begin()) {
            it--;
            it->second--;
            if (it->second == 0) {
                d.erase(it);
            }

            d[a[i]]++;
        }

        else {
            d[a[i]]++;
        }
    }

    int ans = 0;
    for (auto e : d) ans += e.second;
    cout << ans;

    
}


