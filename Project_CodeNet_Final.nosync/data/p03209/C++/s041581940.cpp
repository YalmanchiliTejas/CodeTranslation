#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
// #include <numeric> // gcdとかlcmとか C++17から
#include <time.h> // time_t timer; time(&timer); でtimerに現在時刻が代入される．
#include <unistd.h> // sleep関数．引数は秒単位．
using namespace std;

typedef long long ll;


// sortの仕方
// 	■ string s の場合
// 	昇順: sort(s.begin(), s.end())
// 	降順: sort(s.rbegin(), s.rend())
//
// 	■ ll a[N] の場合
// 	昇順: sort(a, a+N)
// 	降順: 不明

// vector の使い方
// 宣言：
// vector<int> v;
// vector<int> v(N);
// 初期化:
// vector<int> v(10, 5); 要素数10，全ての要素の値5．
// vector<int> v = {1, 2, 3};
// 代入：
// v[0] = 3;
// sort:
// sort(v.begin(), v.end());
//

// int alph2int(char character) {
//     int x = character - 'a';
//     return x;
// }

ll my_gcd(ll a, ll b){
	return (b==0) ? a : my_gcd(b, a%b);
}

ll my_lcm(ll a, ll b){
	return a*b / my_gcd(a,b);
}

ll factorial(ll a){
	ll ans = 1;
	for(ll i=a; i>0; i--){
		ans *= i;
	}
	return ans;
}

int main(int argc, char *argv[]){
	ll N,X;
	cin >> N >> X;

	ll S_all[N+1], S_pat[N+1];
	S_all[0] = 1; S_pat[0] = 1;
	for (int i=1; i<=N; i++) {
		S_all[i] = 2*S_all[i-1] + 3;
		S_pat[i] = 2*S_pat[i-1] + 1;
	}

	ll ans = 0;
	int i=N-1;
	while (X != 0) {
		if (X == 1) {
			break;
		} else if (X <  2 + S_all[i]) {
			X--;
			i--;
            if (i == -1) {
                ans++;
                break;
            }
		} else if (X == 2 + S_all[i]) {
			ans += 1 + S_pat[i];
			break;
		} else if (X <  3 + 2*S_all[i]) {
			ans += 1 + S_pat[i];
			X -= 2+S_all[i];
			i--;
            if (i== -1) {
                ans++;
                break;
            }
		} else if (X == 3 + 2*S_all[i]) {
			ans += 1 + 2*S_pat[i];
			break;
		}
	}

	cout << ans << endl;
}