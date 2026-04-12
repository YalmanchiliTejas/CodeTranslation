#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define arrprint(v,n) rep(i,0,n-1)cout << v[i] << " ";cout << endl;
#define matprint(v,n,m) rep(i,0,n-1){rep(j,0,m-1){cout << v[i][j] << " ";}cout << endl;}
using namespace std;
const int mod=1000000007;
const int INF=1001001001;
typedef long long ll;
typedef pair<int,int> P;

ll comb(int n, int r) {
    if(n == 0) return 0;
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v[n][r];
}

int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;
    int n = sz(s);
    ll ans = 0;

    if(k==3){
        if(n <= 3){
        int nn = atoi(s.c_str());
        if(nn < 111){
            puts("0");
            return 0;
        }
        }
    }
    if(k==2){
        if(n <= 2){
        int nn = atoi(s.c_str());
        if(nn < 11){
            puts("0");
            return 0;
        }
        }
    }

    rep(i,0,n-2){
        if(s[i] == '0')continue;
        if(k==0)break;
        int zan = n - (i+1);
        // cout << comb(zan,k)*pow(9,k) + comb(zan,k-1)*(int)(s[i]-'1')*pow(9,k-1) << endl;
        ans += comb(zan,k)*pow(9,k) + comb(zan,k-1)*(int)(s[i]-'1')*pow(9,k-1);
        k--;
    }
    if(k==0){
        ans++;
    }else{
        if(k==1){
            if(s[n-1] == '0') ans += 0;
            else ans += (int)(s[n-1] - '0');
        }else{

        }
    } 

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}