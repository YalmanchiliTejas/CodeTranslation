#include <iostream>
#include <string>
#include <algorithm>
// #include <numeric> // gcdとかlcmとか C++17から
#include <time.h> // time_t timer; time(&timer); でtimerに現在時刻が代入される．
#include <unistd.h> // sleep関数．引数は秒単位．
using namespace std;

typedef long long ll;

/*sortの仕方
 * ■ string s の場合
 * 昇順: sort(s.begin(), s.end())
 * 降順:  sort(s.rbegin(), s.rend())
 *
 * ■ ll a[N] の場合
 * 昇順: sort(a, a+N)
 * 降順: 不明
 */

/*ll alph2ll(char character) {
    ll x = character - 'a';
    return x;
}
*/

// ll my_gcd(ll a, ll b){
// 	return (b==0) ? a : my_gcd(b, a%b);
// }
//
// ll my_lcm(ll a, ll b){
// 	return a*b / my_gcd(a,b);
// }


int main(){
	int N;
	cin >> N;

	int A[N];
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	sort(A, A+N);

    int updown[N], downup[N];
    for(int i=0; i<N; i++){
        if(i%2 == 0){
            updown[i] = -1;
            downup[i] = 1;
            if(i!=0 && i!=N-1){
                updown[i] *= 2;
                downup[i] *= 2;
            }
        } else {
            updown[i] = 1;
            downup[i] = -1;
            if(i!=0 && i!=N-1){
                updown[i] *= 2;
                downup[i] *= 2;
            }
        }
    }

    sort(updown, updown + N);
    sort(downup, downup + N);

    ll tmp1 = 0, tmp2 = 0;
    for(int i=0; i<N; i++){
        tmp1 += (ll)A[i]*(ll)updown[i];
        tmp2 += (ll)A[i]*(ll)downup[i];
    }

    cout << max(tmp1, tmp2) << endl;
    return 0;
}