#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define MOD (1000000007ll)
#define l_ength size
#define PI 3.14159265358979
 
void mul_mod(ll& a, ll b){
    a *= b;
    a %= MOD;
}
 
void add_mod(ll& a, ll b){
    b += MOD;
    a += b;
    a %= MOD;
}

int main(void){
    int n,i,m;
    ll a[225816];
    vector<ll> b;
    cin >> n;
    m = n/2;
    for(i=0; i<n; ++i){
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    for(i=0; i<n; ++i){
        cout << ((a[i]<b[m])?b[m]:b[m-1]) << endl;
    }
    return 0;
}
