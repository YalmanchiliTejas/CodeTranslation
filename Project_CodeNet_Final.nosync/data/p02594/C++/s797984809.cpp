#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FOR1(i, n) for(int (i)=1; (i)<=(n); (i)++)
#define FORI(i, n) for(int (i)=n-1; (i)>=0; (i)--)
template<class T, class U> void umin(T& x, const U& y){ x = min(x, (T)y);}
template<class T, class U> void umax(T& x, const U& y){ x = max(x, (T)y);}
template<class T, class U> void init(vector<T> &v, U x, size_t n) { v=vector<T>(n, x); }
template<class T, class U> void init(vector<T> &v, U x, size_t n, size_t m...) { v=vector<T>(n); for(auto& a : v) init(a, x, m);}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout << setprecision(15);
    if (argc == 2 && atoi(argv[1]) == 123456789) freopen("d:\\code\\cpp\\contests\\stdin", "r", stdin);

    int x;
    cin >> x;
    if ( x >= 30)
        cout << "Yes";
    else
        cout << "No";

    if (argc == 2 && atoi(argv[1]) == 123456789) cout << clock()*1.0/CLOCKS_PER_SEC << " sec\n";
    return 0;
}

