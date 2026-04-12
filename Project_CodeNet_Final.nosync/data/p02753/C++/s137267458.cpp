#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

template<class T> T umax(T a,T b) {return (a>b?a:b);}
template<class T> T umin(T a,T b) {return (a<b?a:b);}
template<class T,class P> T umax(T a,P b) {return (a>b?a:b);}
template<class T,class P> T umin(T a,P b) {return (a<b?a:b);}

typedef long long int ll;
const int maxn = 1e5+7;
const ll mod = 1e9+7;

bool compare(const pair<ll,ll>& x, const pair<ll,ll>& y) {
    if(x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

ll power(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b&1) {
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    string s;
    cin >> s;
    bool ans = false;
    for(int i=0;i<s.length();i++) {
        for(int j=i+1;j<s.length();j++) {
            if(s[i] != s[j]) {
                ans = true;
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}