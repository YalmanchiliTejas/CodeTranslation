#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int,int> pr;
#define fr(i, n) for(int i = 0; i < n; i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c)(c).begin(), (c).end()
#define tr(c, i) for (typeof ((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())
// for mod power a^b%m use power<lli> (a,b,m)
template < class mytype >
mytype power(mytype a, mytype b, mytype m){if (b == 1) return a % m;if (b == 0) return 1;
mytype root = power < lli > (a, b / 2, m);mytype ans = (root * root) % m;if (b % 2) ans = (ans * a) % m;
return ans;
}
// for gcd use gcd<int> (a,b)
template < class type >type gcd(type a, type b){if (a == 0) return b;else return gcd(b % a, a);}
template < class type >type mod_inv(type a, type p) {return power(a, p - 2, p);}
const lli MOD = 1e9 + 7;

int main()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for(int i = 0 ; i < n ; i++){
    cin >> v[i];
   }
   lli dp[n][n];
   dp[0][0] = 0;
   for(int len = 0 ; len < n ; len++){
    for(int j = 0 ; j+len < n ; j++){
        if(len == 0) dp[len][j] = v[j];
        else{
            dp[len][j] = max(v[j] - dp[len-1][j+1] , v[j+len] - dp[len-1][j]);
        }
    }
   }
   cout << dp[n-1][0];
    return 0;
}









