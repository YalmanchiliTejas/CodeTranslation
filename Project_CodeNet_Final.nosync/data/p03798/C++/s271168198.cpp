
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

bool check(string &s, string &kind) {
    int n = kind.size();
    for (int i = 2; i < n; ++i) {
        if (s[i-1] == 'o' && kind[i-1] == 'S' && kind[i-2] == 'S' ||
            s[i-1] == 'x' && kind[i-1] == 'S' && kind[i-2] == 'W' ||
            s[i-1] == 'o' && kind[i-1] == 'W' && kind[i-2] == 'W' ||
            s[i-1] == 'x' && kind[i-1] == 'W' && kind[i-2] == 'S') {
            kind[i] = 'S';
        } else {
            kind[i] = 'W';
        }
    }
    return (s[0] == 'o' && kind[0] == 'S' && kind[1] == kind[n-1] ||
            s[0] == 'x' && kind[0] == 'S' && kind[1] != kind[n-1] ||
            s[0] == 'o' && kind[0] == 'W' && kind[1] != kind[n-1] ||
            s[0] == 'x' && kind[0] == 'W' && kind[1] == kind[n-1]) && 
           (s[n-1] == 'o' && kind[n-1] == 'S' && kind[0] == kind[n-2] ||
            s[n-1] == 'x' && kind[n-1] == 'S' && kind[0] != kind[n-2] ||
            s[n-1] == 'o' && kind[n-1] == 'W' && kind[0] != kind[n-2] ||
            s[n-1] == 'x' && kind[n-1] == 'W' && kind[0] == kind[n-2]); 
} 

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string kind(n, ' ');
    
    kind[0] = 'S'; kind[1] = 'S';
    if (check(s, kind)) {
        cout << kind << endl;
        return 0;
    }
    kind[0] = 'S'; kind[1] = 'W';
    if (check(s, kind)) {
        cout << kind << endl;
        return 0;
    }
    kind[0] = 'W'; kind[1] = 'S';
    if (check(s, kind)) {
        cout << kind << endl;
        return 0;
    }
    kind[0] = 'W'; kind[1] = 'W';
    if (check(s, kind)) {
        cout << kind << endl;
        return 0;
    }
    cout << -1 << endl;
}
