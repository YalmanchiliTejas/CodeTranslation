#include <cstdio>
#include <string>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <tuple>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i=a;i<n;++i)
#define repeq(i, a, n) for(int i=a;i<=n;++i)
#define repi(m, itr) for (auto itr = m.begin();itr != m.end();++itr)
#define per(i, a, n) for (int i=n-1; i>=a;--i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

// 
ll N;
ll X;
ll ans = 0;

int main(){
    cin >> N >> X;
        ll n = N;
        ll x = X;
    while(true){
        ll burger = pow(2, n+2) - 3;
        ll meat = pow(2, n+1) - 1;
        ll center = (burger+1) / 2;
        if(n==0){
            cout << 1 << endl;
            return 0;
        }
        if(n==1){
            ll a[6] = {0, 0, 1, 2, 3, 3};
            ans += a[x];
            cout << ans << endl;
            return 0;
        }
        if(x == center){
            ans += (meat+1)/2;
            cout << ans << endl;
            return 0;
        }else if(x == burger){
            ans += meat;
            cout << ans << endl;
            return 0;
        }else if(x == 1){
            cout << ans << endl;
            return 0;
        }else if(x<center){
            x -= 1;
            n -= 1;
        }else{
            ans += (meat+1)/2;
            x -= center;
            n -= 1;
        }
    }

    cout << ans << endl;
    return 0;
}


