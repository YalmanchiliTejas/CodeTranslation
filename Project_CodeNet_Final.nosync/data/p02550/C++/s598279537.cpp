#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a > b){ a = b; return true; }else return false; }
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;
using vpi = vector<Pi>;
using vpl = vector<Pl>;
 
#define debug(arr) cout << #arr << " = " << arr << '\n'
#define debug2(a,b) cout << "[" << #a << "," << #b << "] = " << "[" << a << "," << b << "]" << '\n'
template<class T> ostream &operator << (ostream& out, const vector<T>& arr) {
	cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
	return out;
}
template<class T> ostream &operator << (ostream& out, const vector<vector<T> >& arr) {
	cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
	return out;
}
template<class S,class T> ostream &operator << (ostream& out, const pair<S,T>& p){
  cout << "{" << p.first << "," << p.second << "}" << '\n';
  return out;
}
template<class T> istream &operator >> (istream& in, vector<T>& arr) {
	for (auto& i : arr)cin >> i; return in;
}

/////////////////////////////////////////////////////////////////////////
int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(20);
  
  ll n,x,m;cin >> n >> x >> m;
  map<ll,int> M;
  vl cy;
  ll sum = 0;
  ll cnt = 0;
  ll rp = 0;
  while(true){
    if(cnt == n){
      cout << sum << '\n';
      return 0;
    }
    if(x == 0){
      //cout << "zero" << '\n';
      cout << sum << '\n';
      return 0;
    }else if(x == 1){
      //cout << "one" << '\n';
      cout << (n - cnt) + sum << '\n';
      return 0;
    }else if(M.count(x)){
//      cout << "hit " << x << '\n';
      rp = cnt - M[x];
      break;
    }
    M[x] = cnt;
    sum += x;
    cy.pb(x);
    x = (x * x) % m;
    cnt++;
  }

  ll s2 = 0;
  for(int i = cnt - rp;i < cnt;i++) s2 +=cy[i];
  ll r = (n - cnt) % rp;
  ll add = 0;
  for(int i = cnt - rp;i < cnt - rp + r;i++) add += cy[i];
  
  ll ans = sum + ((n-cnt)/rp)*s2 + add;
  cout << ans << '\n';
  return 0;
}
