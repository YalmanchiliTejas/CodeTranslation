#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
typedef long long ll;
namespace mp = boost::multiprecision;
using Mint = mp::cpp_int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(all(v)), v.end())
#define sort_g(v) sort(all(v), greater<int>())
#define dump(x) cerr << #x << ' ' << '=' << ' ' << x << endl

int main() {
    string S;
    cin >> S;
    if(S.find("AC") != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;
}