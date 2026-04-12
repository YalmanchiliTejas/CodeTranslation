#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int N = 1e5+9;
const ll INF = 1LL<<60;

int n;
vector<ll> load(N, INF);

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; a = -a;
        *upper_bound(load.begin(), load.end(), a) = a;
    }
    ll nothing = count(load.begin(), load.end(), INF);
    cout << load.size() - nothing << endl;
}