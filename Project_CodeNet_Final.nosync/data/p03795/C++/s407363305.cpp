#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define each(i, c) for (auto& (i) : (c))

using namespace std;
typedef long long int ll;
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }

int main() {
    int n;
    cin >> n;
    cout << n*800-int(n/15)*200 << endl;
    return 0;
}