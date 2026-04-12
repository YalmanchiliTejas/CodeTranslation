#include <bits/stdc++.h>

using namespace std;

struct vw_pair {
    int v, w;
    vw_pair(int v,int w) : v(v), w(w) {};
};

typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
typedef vector <string> vs;
typedef vector <vi> vvi;
typedef vector <vector<vw_pair>> adj_list;
typedef vector <bool> vb;
typedef long long ll;
typedef unsigned long long ull;

int find_LIS(vi& a) {
    int n = a.size();
    vi L, PL;
    L.push_back(a[0]);
    int max_pos = 0;
    for (int i=1;i<n;++i) {
        int k = upper_bound(L.begin(),L.end(),a[i]) - L.begin();
        if (k == L.size()) {
            L.push_back(a[i]);
        } else if (L[k] > a[i]) {
            L[k] = a[i];
        }
    }
    return L.size();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, xx;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;++i) {
        cin >> a[i];
        a[i] = -a[i];
    }
    int color = 0;
    cout << find_LIS(a) << "\n";
    return 0;
}