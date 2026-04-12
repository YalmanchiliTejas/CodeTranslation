#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(ull i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)
#define iter(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define riter(i,c) for(auto i=(c).rbegin(); i!=(c).rend(); ++i)

const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

#define clr(a,i) memset((a), (i) ,sizeof(a))

int main(){
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  rep(i,n){
    std::cin >> a[i];
  }
  sort(all(a));
  reverse(all(a));
  long long ans=0;
  bool b=false;
  while(!b){
    long long tmp =0,tmp2;
    rep(i,a.size()){
      ans+=a[i]/n;
      tmp+=a[i]/n;
    }
    rep(i,a.size()){
      tmp2=a[i];
      a[i]=tmp2%n;
      a[i]+=tmp-tmp2/n;
    }
    b=true;
    rep(i,a.size()){
      if(a[i]>n-1) b=false;
    }
  }

  std::cout << ans << std::endl;
}
