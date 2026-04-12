#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long LL;
const int INF = 999999999;
const LL mod = 1000000007;

int main(){
    LL a,b,x;
    cin >> a >> b >> x;
    if(x < a){
        cout << x%mod << endl;
        return 0;
    }
    LL t = ((x-b) / (a-b)) % mod;
    cout << (x%mod + t*(b%mod))%mod << endl;
}

