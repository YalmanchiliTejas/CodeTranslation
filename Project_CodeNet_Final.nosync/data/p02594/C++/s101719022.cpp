#include <bits/stdc++.h>
using namespace std;

#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define ll unsigned long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)

#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int Maxn = (int)1e6+1;
const ld pi = acos(-1);
int mod = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 0, (int)A.size()) out << A[i] << " ";
    return out;
}

template <class T1, class T2>
ostream &operator<<(ostream &out, map<T1, T2> &A) {
    for (auto x : A) cout << x.ff << " # " << x.ss << endl;
    return out;
}


int32_t main() {
    IOS
    int n;  cin>>n;
    puts(n >= 30 ? "Yes" : "No");
    return 0;
}