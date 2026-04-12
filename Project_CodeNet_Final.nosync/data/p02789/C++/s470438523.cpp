#include <iostream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <cstdlib>
#include <iomanip>
#include <climits>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 2e9 + 1e8;
const ll INF = 2e18 + 1e17;
const int mod = 998244353;
const int MOD = 1e9 + 7;
 
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}
bool is_prime(ll x) {
	if (x == 1 || (x % 2 == 0 && x > 2))     return false;
	for (int i = 3; i*i <= x; i += 2) {
		if (!(x % i)) {
			return false;
		}
	}
	return true;
}
 
/**************************************************************************************
***************************************************************************************/
const int MAXN = 100010;

int N, M;

int main (){
    ios_base::sync_with_stdio(false);   cin.tie(false);
    cin>>N>>M;
    cout<<(N == M ? "Yes" : "No")<<endl;
    
    return 0;
}