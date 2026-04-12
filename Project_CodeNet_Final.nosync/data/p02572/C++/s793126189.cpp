#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int n;  cin >> n;
    ll tmp, ans;
    ll a;   cin >> a;
    tmp = a;
    ans = 0;
    for(int i=1; i<n; i++){
        ll d;   cin >> d;
        ans += tmp*d;
        tmp += d;
        tmp %= MOD;
        ans %= MOD;
    }
    print((ans+MOD)%MOD);
}