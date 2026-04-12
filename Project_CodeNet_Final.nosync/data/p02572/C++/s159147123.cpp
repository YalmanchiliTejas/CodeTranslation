#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    unsigned long long n, ans = 0, mod = 1000000007;
    cin >> n;
    vector<unsigned long long> a(n);
    unsigned long long po = 0, tot = 0; 
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
        po += (a.at(i) * a.at(i)) % mod;
        tot += a.at(i);
    }
    tot %= mod; po %= mod;
    ans = (tot * tot) - po;
    ans %= mod;
    //2で割る (逆元を用いる)
	//ans /= 2 を mod 1000000007で行うとこうなる
	ans *= (mod + 1) / 2;
	ans %= mod;
    cout << ans << endl;
    return 0;
}