/*                        _
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                   ____/`---'\____
                  /  \\|     |//  \
                 / \\||| /:\ |||// \
                / _||||| -:- |||||- \
               |   | \\\ \-/ /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
            ____'. .'  /--.--\  `. .'_____
          /"" '<  `.___\_<|>_/___.' >' "" \
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` / _/
          `-.____`.___ \_____/___.-`___.-'

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 JENISH MONPARA S.    IIT PATNA    I_LOVE_ADITI_GOEL
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793;
const long double DEL = 1e-12;
const int mod =  1000000007;
const int LIM = 100005;


#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mpq priority_queue<int,vector<int>,greater<int>>
#define deb(a) cerr << #a << ": " << a << endl
#define ftt cin>>t;for(int tt=1;tt<=t;++tt)
#define forr(i,n) for((i)=1;(i)<=(n);(i)++)
#define Rev(v) reverse(v.begin(),v.end())
#define Sort(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a))
#define umii unordered_map<int,int>
#define all(a) a.begin() , a.end()
#define vvi vector<vector<int>>
#define pq priority_queue<int>
#define sqr(a) (((a) * (a)))
#define double long double
#define dbg cout<<"\nhi\n"
#define pii pair<int,int>
#define mii map<int,int>
#define vb vector<bool>
#define eb emplace_back
#define vi vector<int>
#define nl cout<<"\n"
#define pb push_back
#define int long long
#define sp <<" "<<
#define se second
#define fi first
 
int fpow(int x, int n){
    int res = 1;
    while(n){
          if(n&1){
                res = res * x % mod;
          }
          x = x * x % mod;
          n>>=1;
    }
    return res;
}
int gcd(int a,int b){
    if(b == 0)return a;
    return gcd(b,a % b);
}
void sieve(int n){
     bool prime[5*LIM];
     memset(prime, true, sizeof(prime));
      int rootn = (int)sqrt(n);
     for (int p = 2; p <= rootn; p++)
          if (prime[p] == true)
               for (int i = p*p; i <= n; i += p)
                    prime[i] = false;
     prime[1] = 0;

}

int cnt, mid, mx = -1e17, mn = 1e17, a[2*LIM];
int n, m, d, t, i, j, k, l, r, x, y, z;
bool f, f1, f2;
string s;

//******************************************* CHECK CONSTRAINTS **************************************************
vector<vector<int>> dp (3010,vector<int>(3010,-1));
vi sum(5000,0);
int jao(int l,int r){
      if(dp[l][r]>=0){
            return dp[l][r];
      }
      dp[l][r]= max(sum[r] - sum[l-1] - jao(l+1,r),sum[r] - sum[l-1] - jao(l,r-1));
      return dp[l][r];
}

int32_t main()
{     fio;
      cin>>n;
      forr(i,n){
            cin>>a[i];
            dp[i][i]=a[i];
            //dp[i][i][0]=a[i];
            sum[i]=a[i]+sum[i-1];
      }
      cout<<2*jao(1,n)-sum[n];
     
}
