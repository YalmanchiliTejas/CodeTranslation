#include <iostream>
#include <vector>
#include <string>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a,i##_len=(b);i<i##_len;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
typedef long long ll;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
    string s;
    cin >> s;

    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
