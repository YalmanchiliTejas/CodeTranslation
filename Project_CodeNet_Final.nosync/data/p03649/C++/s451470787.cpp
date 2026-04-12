#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

int main(){
  int n;
  cin>>n;
  vector<long> vec(n);
  rep(i,n) cin>>vec[i];

  auto ok = [&](){
    rep(i,n) if(vec[i]>=n) return false;
    return true;
  };

  long mn = *min_element(all(vec));
  long ans = 0;

  rep(i,n){
    long x = (vec[i]-mn)/(n+1);
    ans += x;
    vec[i] -= (n+1)*x;
  }

  rep(i,n) vec[i] += ans;

  mn = *min_element(all(vec));

  if(mn-n>0){
    ans += (mn-n)*n;
    rep(i,n) vec[i] -= (mn-n);
  }

  while(!ok()){
    int x = 0;
    rep(i,n) if(vec[i] > vec[x]) x = i;
    rep(i,n) vec[i] +=1;
    vec[x] -= n+1;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
