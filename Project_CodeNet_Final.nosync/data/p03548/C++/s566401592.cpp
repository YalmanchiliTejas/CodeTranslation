#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);
#define setnow clock_t tStart;
#define setTime tStart = clock();
#define time0 (double)(clock() - tStart)/CLOCKS_PER_SEC
#define setin(x) ifstream cin(x);
#define setout(x) ofstream cout(x);
#define NMAX 30
typedef long long ll;
typedef long long int lli;
typedef pair < int, int> dbl;
const int maxInt = 1e9*2;
const lli maxLong = 1e18*2;
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int ans = x/(y+z);
    if ( x - ans*(y+z) < z)
        ans--;
    cout << ans;
	return(0);
}
