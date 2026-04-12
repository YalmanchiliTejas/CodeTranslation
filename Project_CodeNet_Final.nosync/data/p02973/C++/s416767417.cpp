#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

vin leader;//大きのが前

bool judge(int x,int a){
  return leader[x]<a;
}



int main(){cout<<fixed<<setprecision(10);
		   int n;
           cin>>n;
           vin a(n);
           rep(i,0,n)cin>>a[i];
           int ans=0;
           //cout<<ans<<endl;
           //二分探索で更新していくO(nlogn)
           leader.resize(0);
           int mn=inf;
           rep(i,0,n){
             if(mn>=a[i]){
              mn=a[i];
               leader.pb(a[i]);
               ans++;
             }
             else{//mn<a[i]
               //leader[x]<a[i]なる最小のxを探す
               int ng=-1;
               int ok=leader.size()-1;
               while(ok-ng>1){
                int mid=(ng-ok)/2+ok;
                 if(judge(mid,a[i]))ok=mid;
                 else ng=mid;
               }
               leader[ok]=a[i];
               if(ok==leader.size()-1)mn=a[i];
             }
           }
			cout<<ans<<endl;
}