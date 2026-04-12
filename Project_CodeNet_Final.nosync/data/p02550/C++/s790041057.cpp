#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;
ll DEN2 = 998244353LL;

using namespace std;

ll n, m, k;
ll h, w;

ll calc_gcd(ll a, ll b){
    if (a<b){
        ll c = a;
        a = b;
        b = c;
    }
    while(a%b != 0){
        ll c = b;
        b = a%b;
        a = c;
    }
    return b;
}

int main(){
    ll x;
    cin >> n >> x >> m;
    vector<ll> fc(m,-1);
    ll rep = m-1;
    ll fs = 0;
    vector<ll> val(2*m);
    for(int i=0; i<2*m;++i){
        if(fc[x] != -1){
            rep = i - fc[x];
            fs = fc[x];
            break;
        }
        fc[x] = i;
        val[i] = x;
        x = (x*x) % m;
    }
    ll ret = 0;
    if(n < fs){
        ret = accumulate(val.begin(), val.begin()+n, 0LL);
    }else{
        n -= fs;
        ret += accumulate(val.begin()+fs, val.begin()+rep+fs, 0LL) * (n / rep);
        ret += accumulate(val.begin(), val.begin()+(n%rep)+fs, 0LL);
    }
    cout << ret << endl;
    return 0;
}
