#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(void){
  string n; cin >> n;
  ll k; cin >> k;
  ll nlen = n.length();
  ll ans = 0;

  FOR(i,1,nlen-1){
    if(i<k) continue;

    if(k==1) ans += 9;
    else if(k==2){
      ans += (i-1) * 81;
    }
    else {
      ans += (i-1) * (i-2) * 729 / 2;
    }
  }

  if(k==1){
    ans += (n[0]-'0');
  }
  else if(k==2){
    int ret = 1;
    while(n[ret]=='0' && ret<nlen){
      ++ret;
    }
    if(ret!=nlen){
      ans += (n[ret] - '0');
      // ans += ((n[0] - '0') - 1) * 9;
      // ans += (n[0] - '0') * (nlen-ret-1) * 9;
      ans += (nlen-ret-1) * 9;
    }
    ans += ((n[0] - '0') - 1) * 9 * (nlen-1);
  }
  else{
    int reta,retb; 
    reta = 1; 
    retb = -1;
    while(n[reta]=='0' && reta<nlen){
      ++reta;
    }
    if(reta!=nlen){
      retb = reta + 1;
      while(n[retb]=='0' && retb<nlen){
        ++retb;
      }
    }

    if(reta!=nlen){
      if(retb!=nlen){
        ans += (n[retb] - '0');
        ans += 9 * (nlen-retb-1);
        ans += ((n[reta] - '0') - 1) * 9 * (nlen-reta-1);
        ans += (nlen-reta-1) * (nlen-reta-2) * 81 / 2;
      } else {
        ans += ((n[reta] - '0') - 1) * 9 * (nlen-reta-1);
        ans += (nlen-reta-1) * (nlen-reta-2) * 81 / 2;
      }
      ans += (nlen-1) * (nlen-2) * (n[0] - '0' - 1) * 81 / 2;
    }
  }

  cout << ans << endl;
}