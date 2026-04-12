// <head>
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    const int INF = 1002003004;
    const ll LINF = 1002003004005006007ll;
    struct preprocess{preprocess()
    {cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}}____;
// </head>

// <library>
    const int MOD = 998244353;
    struct mint {
      ll x; // typedef long long ll;
      mint(ll x=0):x((x%MOD+MOD)%MOD){}
      mint operator-() const { return mint(-x);}
      mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
      }
      mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
      }
      mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
      }
      mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
      }
      mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
      }
      mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
      }
      mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
      }
      // for prime MOD
      mint inv() const {
        return pow(MOD-2);
      }
      mint& operator/=(const mint a) {
        return (*this) *= a.inv();
      }
      mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
      }
    };
    ostream& operator<< (ostream& os, const mint& value) {
      os << value.x;
      return os;
    }
    
// </library>
const int MX = 3005;
mint dp[MX][MX][3];

int main(){
    int n,s; cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    dp[0][0][0] = 1;
    for (int i = 1; i < n+1; i++){
        for (int j = 0; j < MX-1; j++){
            for (int k = 0; k < 3; k++){
                int pi = i-1,pj=j-a[pi];
                int pk = k-1;
                dp[i][j][k] = dp[pi][j][k];
                if(pj >= 0 && k==1) dp[i][j][k] += dp[pi][pj][k]  + dp[pi][pj][pk];
                if(pk>=0) dp[i][j][k] += dp[pi][j][pk];
            }
        }
    } 
    cout << dp[n][s][1] + dp[n][s][2] << '\n';
    
}