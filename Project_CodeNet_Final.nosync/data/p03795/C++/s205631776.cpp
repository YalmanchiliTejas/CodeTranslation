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

    ll N;
    cin >> N;
    ll x = 800 * N;
    ll y = N / 15 * 200;
    cout << x - y << endl;

    return 0;
}