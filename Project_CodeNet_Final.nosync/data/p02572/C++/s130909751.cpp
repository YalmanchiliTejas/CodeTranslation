#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int N;
    long long a, ans = 0, s = 0;
    const long long mod = pow(10,9)+ 7;
    cin >> N;
    for( int i=0; i<N; i++){
        cin >> a;
        //cout << "(1) ans = " << ans << ", s = " << s << endl;
        ans = (ans + (a * s) % mod ) % mod;
        s = ( s + a ) % mod;
        //cout << "(2) ans = " << ans << ", s = " << s << endl;
    }
    cout << ans << endl;
}