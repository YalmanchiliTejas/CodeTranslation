#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> vec;
    vec.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        int start = 0;
        int end = vec.size() - 1;
        while (end - start > 1) {
            int med = (start + end) / 2;
            if (vec[med] < a[i]) {
                start = med;
            }
            else {
                end = med;
            }
        }
        if (vec[end] < a[i]) {
            vec[end] = a[i];
        }
        else if (vec[start] < a[i]) {
            vec[start] = a[i];
        }
        else {
            vec.insert(vec.begin(), a[i]);
        }
    }
    cout << vec.size() << endl;
   return 0;
}