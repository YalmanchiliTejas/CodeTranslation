//include
//------------------------------------------
#include <bits/stdc++.h> // only for GCC

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

//container util
//------------------------------------------
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair

//repetition
//------------------------------------------
#define loop(i,a,b) for(ull i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)
#define iter(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define riter(i,c) for(auto i=(c).rbegin(); i!=(c).rend(); ++i)

//constant
//--------------------------------------------
const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

// output vector
// ------------------------------------------
namespace std {
    template<typename T>ostream&operator<<(ostream&os, vector<T>const&v){
        iter(it,v) os<<*it<<(it+1==v.end()?"":",");
        return os;
    }
    template<typename T, typename U>ostream&operator<<(ostream&os,const pair<T,U>&p){
        return os << "[" << p.dirst << "," << p.second << "]";
    }
}

//clear memory
// ------------------------------------------
#define clr(a,i) memset((a), (i) ,sizeof(a))

int main(){
   int n,m;
   vector<pii> x;
   char c;
   while(cin >> n >> c >> m && n|m){
      x.pb(mp(m,n));
   }
   sort(all(x));
   reverse(all(x));
   int r=1, tmp;
   rep(i,x.size()){
      if(i==0){
         tmp=x[i].first;
         x[i].first=r;
      }else if(x[i].first<tmp){
         tmp=x[i].first;
         r++;
         x[i].first=r;
      }else x[i].first=r;
   }
   while(cin >> n){
      rep(i,x.size()) if(x[i].second==n) cout << x[i].first << endl;
   }
}