#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<ll, ll>P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void SAY(bool YES){cout<<(YES?"YES":"NO")<<endl;};
void Say(bool Yes){cout<<(Yes?"Yes":"No")<<endl;};

const ll MOD = 1000000007;

int main(){

    ll r, g, b;
    cin >> r >> g >> b;
    SAY((r * 100 + g * 10 + b) % 4 == 0);

    return 0;
}