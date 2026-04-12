#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map> 
#include <set>
#include <vector>
#include <list>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(s,i,n) for(int i=s;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define skip(i,n,p) for(int i=0;i<n;i+=p)
#define ll long long
#define debug cout << __FILE__ << ":" << __LINE__ << endl;

template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) {
    if (v.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << v.front();
    for (auto itr = ++v.begin(); itr != v.end(); itr++) {
        ostr << ", " << *itr;
    }
    ostr << "}";
    return ostr;
}

int gcd(int a, int b) {
    if (a < b) a, b = b, a;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

void solve() {
    string S;
    cin >> S;

    rep(i, S.size()-1) {
        if(S[i] == 'A' && S[i+1] == 'C') {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    cout.precision(20);
    cout << fixed;

    solve();
}
