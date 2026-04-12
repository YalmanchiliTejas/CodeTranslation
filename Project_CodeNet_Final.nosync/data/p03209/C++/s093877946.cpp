#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<v_char > v2_char;
typedef std::vector<double> v_double;
typedef std::vector<v_double > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std; 

ll burger[50][2];

ll dfs_all(int n) 
{
    if(n == 0) {
        return 1;
    }
    burger[n][0] = 2 * dfs_all(n-1)+3;
    return burger[n][0];
}

ll dfs_beaf(int n) 
{
    if(n == 0) { return 1; }
    burger[n][1] = 2 * dfs_beaf(n-1)+1;
    return burger[n][1];
}

ll dfs_eat(int n, ll x)
{
    if(n == 0) { return 1; } 

    if(x == 1) {
        return 0;
    } else if(1 + burger[n-1][0] >= x) {

        return dfs_eat(n-1, x-1);

    } else if(1 + burger[n-1][0] + 1 == x) {

        return burger[n-1][1] + 1;

    } else if(2 + 2*burger[n-1][0] >= x) {

        return burger[n-1][1] + 1 + dfs_eat(n-1, x-burger[n-1][0]-2);

    } else {
        return burger[n][1];
    }
}

int main(void)
{
    ll n, x;
    cin >> n >> x;
    //cin >> n;
        
    burger[0][0] = 1;
    burger[0][1] = 1;

    dfs_all(n);
    dfs_beaf(n);

    //irep(i, n+1) { printf("%lu,%lu\n", burger[i][0], burger[i][1]); }

    cout << dfs_eat(n,x);
    
    return 0;
}
/** tcoder **/
