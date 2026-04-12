/*
 * Author : Sadi
 * Fri 03/07/2020 * 18:09:36.25
 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

#define    watch(x); cout << "\n" <<  #x << " is: " << x << "\n";
#define    all(a) (a).begin(), (a).end()
#define    fi first
#define    se second

template<class A, class B>
ostream& operator << (ostream& output, const pair<A, B>& p) {
    output << "(" << p.first << ", " << p.second << ")";
    return output;
}

template<class A>
ostream& operator << (ostream& output, const vector<A>& a) {
    output << "[";
    for(auto it = a.begin(); it != a.end(); ++it) {
        if(it != a.begin()) {
            output << ", ";
        }
        output << *it;
    }
    output << "]";
    return output;
}

using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

//const int inf = 1e9;
//const int mod = 1e9 + 7;
//const double PI = acos(-1.0);
//const int mx = 1e5 + 5;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    int x;
    cin >> x;
    if(x == 7 or x == 5 or x == 3) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
