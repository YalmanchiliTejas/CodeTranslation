#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define fi first
#define se second
#define NMAX 100005
const long double PI = acos(-1);

int uz[2][NMAX],a,b,n,q,pos;
unordered_set<int> L, R, Lp, Rp, S;

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> q;
  pos = 1;
  S.insert(2);
  int nimic = 0, nimeni = 0;
  for (int i=1;i<=q;i++){
    cin >> a >> b;
    
    if (S.count(a) && S.count(b)){
        nimic = nimeni;
    }
    else if (S.count(a)){
      S.erase(a);
      S.insert(b);
    }
    else if (S.count(b)){
      S.erase(b);
      S.insert(a);
    }

    if (pos == a){
      pos = b;
    }
    else if (pos == b){
      pos = a;
    }

    if (pos - 1 > 0){
      S.insert(pos - 1);
    }
    if (pos + 1 <= n){
      S.insert(pos+1);
    }

  }

  S.insert(pos);

  cout << S.size() << '\n';

  return 0;
}