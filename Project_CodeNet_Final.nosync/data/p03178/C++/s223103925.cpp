#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define X real()
#define Y imag()

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll  = long long;

using point = complex<double>;


void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}

const int N = 2e5 + 50;
const double EPS = 1e-8;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,1 , -1,1 ,-1 , 1 , -1};
const int dy[] = {1,-1,0 , 0,1 , -1 , -1 , 1};



int  d;
string k;
long long dp[N][102][2]; // dp[indx][mod][isSmaller]

long long solve(int indx ,int m , bool isSmaller){
            if(indx == k.size())
                    return m == 0;
            long long &ret = dp[indx][m][isSmaller];
            if(~ret)
                    return ret;
            ret = 0;
            int lim;
            if(isSmaller)
                lim = 9;
            else
                lim = k[indx] - '0';
            for(int i = 0; i <= lim; ++i){
                //if(indx == 0 && i == 0) continue;
                int nMod = (m + i)%d;
                bool s = isSmaller;
                if(!s){
                    if(i < k[indx]-'0')
                        s = 1;
                }
                ret += solve(indx + 1, nMod, s);
                ret %= mod;
            }
            return ret % mod;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> d;
    memset(dp,-1,sizeof dp);
    cout << (solve(0,0,0) - 1 + mod) % mod << '\n';


    return 0;
}