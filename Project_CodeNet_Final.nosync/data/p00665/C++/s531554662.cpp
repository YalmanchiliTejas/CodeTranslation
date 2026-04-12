#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, string> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll N,M,K,L;
bool isfav[100010];
vector<ll> A,fav;
vector<string> S;
map<string,ll> id;
vector<ll> ord;

bool ok(ll X){
  if(X>K)return false;

  ll cnt=0;
  rep(i,K){
    if(isfav[ord[i]])cnt++;
  }
  if(X<=cnt)return true;

  ll add=X;
  ll rest=X-cnt;
  ll sum=0;
  for(ll i=K-1;i>=0;i--){
    if(!isfav[ord[i]]){
      rest--;
      if(rest==0){
        rep(j,N){
          if(isfav[ord[j]]){
            if(j>i){
              if(S[ord[i]]<S[ord[j]]) sum+=A[ord[i]]-A[ord[j]]+1;
              else sum+=A[ord[i]]-A[ord[j]];
            }
            add--;
            if(add==0)break;
          }
        }
        break;
      }
    }
  }
  return sum<=L;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(1){
    A.clear(); S.clear(); fav.clear(); ord.clear();
    id.clear();
    cin>>N>>M>>K>>L;
    if(N==0)break;
    rep(i,N)isfav[i]=false;
    A.resize(N);
    S.resize(N);
    rep(i,N){
      string name;
      cin>>S[i]>>A[i];
      id[S[i]]=i;
    }
    rep(i,M){
      string name;
      cin>>name;
      fav.push_back(id[name]);
      isfav[id[name]]=true;
    }

    rep(i,N){
      ord.push_back(i);
    }
    sort(all(ord),[=](const ll& a,const ll& b){
      if(A[a]==A[b])return S[a]<S[b];
      else return A[a]>A[b];
    });

    //rep(i,N){
      //dbg(S[ord[i]]);
    //}

    ll lb=0,ub=M+1;
    while(ub-lb>1){
      ll mid=(ub+lb)/2;
      if(ok(mid)) lb=mid;
      else ub=mid;
    }
    cout<<lb<<endl;
  }

  return 0;
}

