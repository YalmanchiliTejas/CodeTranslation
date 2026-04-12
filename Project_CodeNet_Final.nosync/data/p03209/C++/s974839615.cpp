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
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll pat[55];
ll siz[55];


ll count(ll a,ll b){//aバーガーの下からb層に含まれるpの数
  if(a==0)return (b>0 ? 1: 0);
  if(siz[a]/2>=b) return count(a-1,b-1);
  else{
    return 1+pat[a-1]+count(a-1,b-2-siz[a-1]);
  }
}

int main(){cout<<fixed<<setprecision(20);
		   //a[n+1]=2a[n]+3
           //a[n]=2^(n+2)-3
           //p[n+1]=2p[n]+1
           //p[n]=2^(n)-1
           ll n,x;
           pat[0]=1;
           siz[0]=1;
           rep(i,1,55){
            pat[i]=2*pat[i-1]+1;
            siz[i]=siz[i-1]*2+3;
           }
             
           cin>>n>>x;
           //if(n==1&&x==1)return 0;
           cout<<count(n,x)<<endl;
           
}