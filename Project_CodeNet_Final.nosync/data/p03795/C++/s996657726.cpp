
/*
 * “My code isn't a mess! It's organised chaos!”
 */

/*
 * short     2^15-1 ~ 3e4
 * int       2^31-1 ~ 2e9
 * long x86  2^31-1 ~ 2e9
 * long long 2^63-1 ~ 9e18
 */

#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define fr(a,b) for (int a=0; a<b; ++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1000000007ll;
const int infty = numeric_limits<int>::max();
struct _{_(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}_;
void err() {cerr << endl;}
template<typename T, typename... Ts>
void err(T a, Ts... as) {cerr << a << ' '; err(as...);}

 /*
  * Всегда прогоняй макс-тест перед 
  * нажатием «Отослать». Всегда.
  */ 

int main() {
    int n;
    cin >> n;

    cout << 800 * n - 200 * (n/15) << endl;

    return 0;
}
