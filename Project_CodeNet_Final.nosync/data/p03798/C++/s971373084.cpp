#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec     vector<int>
#define vecll   vector<ll>
#define vecst   vector<string>
#define vecb    vector<bool>

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define f_sum(var)       accumulate(all(var), 0)
#define f_sumll(var)     accumulate(all(var), 0LL)
#define chmin(v1, v2)    v1 = min(v1, v2)
#define chmax(v1, v2)    v1 = max(v1, v2)
#define mpair(v1, v2)    make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << var;
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt((ok ? "Yes" : "No"));}
//----------------------------------------------------------------
string digit(int p, int n, int k){
  // p shinsu, n keta, k banme
  int digit = p;

  string s;
  if(k==0){s="0";}
  while(k>0){
    s.push_back((k%digit)+'0');
    k -= k%digit;
    k /= digit;
  }

  while(s.size()<n){
    s.push_back('0');
  }
  return s;
}

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;


  rep(i,4){
    string tmp=digit(2, 2, i);
    //prt(tmp);
    rep(j,n){
      if(j==0) continue;
      if(tmp[j]=='0'){
        if(s[j]=='o') tmp.pb(tmp[j-1]);
        else tmp.pb((tmp[j-1]=='1' ? '0' : '1'));
      } else {
        if(s[j]=='o') tmp.pb((tmp[j-1]=='1' ? '0' : '1'));
        else tmp.pb(tmp[j-1]);
      }
    }
    if(tmp[n]!=tmp[0]) continue;
    if(((s[0]=='o' && tmp[0]=='0') && tmp[n-1]==tmp[1]) ||
       ((s[0]=='o' && tmp[0]=='1') && tmp[n-1]!=tmp[1]) ||
       ((s[0]=='x' && tmp[0]=='0') && tmp[n-1]!=tmp[1]) ||
       ((s[0]=='x' && tmp[0]=='1') && tmp[n-1]==tmp[1])){
      tmp.pop_back();
      rep(j,n){
        if(tmp[j]=='0') tmp[j]='S';
        else tmp[j]='W';
      }
      prt(tmp);
      return 0;
    }
  }

  prt(-1);
}
