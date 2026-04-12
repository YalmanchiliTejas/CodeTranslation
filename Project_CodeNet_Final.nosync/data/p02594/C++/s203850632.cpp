#include"bits/stdc++.h"
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) {
        return(b);
    }
    else {
        return(gcd(b, a % b));
    }
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

ll mod(ll a, ll b) {
    ll ans = a % b;
    if (ans < 0) {
        ans = b + ans;
    }
    return ans;
}

int main(void) {
    int n;
    cin >> n;
    if (n >= 30) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

}

/*
5 4 3 2 1
*/
