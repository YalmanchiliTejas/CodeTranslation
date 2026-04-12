#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define  st first
#define  nd second
#define int long long

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef cc_hash_table<int, int, hash<int > > ht;
#define TIMES_PER_SEC (CLOCKS_PER_SEC)


double get_absolute_time()
{
	return (double)clock()/TIMES_PER_SEC;
}
double starttime_acrush;
void starttime()
{
	starttime_acrush=get_absolute_time();
}
double gettime()
{
	return get_absolute_time()-starttime_acrush;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define M   1000000007
const int N = 10001;  // limit for array size

int32_t main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int a  , b ;
  cin >> a >> b ;
  if(a==b){

        cout <<"Yes";
  }
  else{
    cout<<"No";
  }
//  cout << ans ;


}

