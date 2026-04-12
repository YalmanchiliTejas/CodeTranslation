#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

using namespace std;    
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main() {

    ll N, K;
    cin >> N >> K;

    // 余りがiになる組み合わせ
    ll ans = 0;
    for(ll b = K + 1; b <= N; b++){
        // N までにある数的な
        ll div = N / b;
        ll rem = N % b;

        ans += (b - K) * (div + 1);
        ans -=  min((b - K),  max ( 0ll, (b - rem - 1) ));
        if(K == 0) ans --;
    }
    cout << ans << endl;

}