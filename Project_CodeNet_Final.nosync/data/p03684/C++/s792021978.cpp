#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;
ll longinf=1ll<<60;
int inf=1<<29;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dh[4]={0,1,0,-1};
int dw[4]={1,0,-1,0};

int main (){
      int N;
      cin>>N;
      P p[N];
      rep0(i,N){
            cin>>p[i].first>>p[i].second;
      }
      sort(p,p+N);
      map<P,vector<Q>> v;
      rep0(i,N){
            if(i!=(N-1)){
                  ll d = abs(p[i+1].first-p[i].first);
                  v[p[i]].push_back({d,p[i+1]});
            }
            if(i!=0){
                  ll d=abs(p[i].first-p[i-1].first);
                  v[p[i]].push_back({d,p[i-1]});
            }
      }
      rep0(i,N){
            swap(p[i].first,p[i].second);
      }
      sort(p,p+N);
      rep0(i,N){
            swap(p[i].first,p[i].second);
      }
      rep0(i,N){
            if(i!=(N-1)){
                  ll d=abs(p[i+1].second-p[i].second);
                  v[p[i]].push_back({d,p[i+1]});
            }
            if(i!=0){
                  ll d=abs(p[i].second-p[i-1].second);
                  v[p[i]].push_back({d,p[i-1]});
            }
            sort(v[p[i]].begin(), v[p[i]].end());
            v[p[i]].erase(std::unique(v[p[i]].begin(), v[p[i]].end()), v[p[i]].end());
      }
      /*rep0(i,N){
            cout<<i<<"  ";
            rep0(j,v[p[i]].size()){
                  cout<<v[p[i]][j].first<<" "<<v[p[i]][j].second.first<<" "<<v[p[i]][j].second.second<<"  ";
            }
            cout<<endl;
      }*/
      map<P,ll> d;
      map<P,bool> merged;
      rep0(i,N){
            d[p[i]]=longinf;
            merged[p[i]]=false;
      }
      d[p[0]]=0;
      priority_queue<Q,vector<Q>,greater<Q>> q;
      q.push({d[p[0]],p[0]});
      ll ans=0;
      while(q.size()){
            Q hoge = q.top();
            q.pop();
            ll di = hoge.first;
            P node = hoge.second;
            if(merged[node]) continue;
            ans+=di;
            merged[node]=true;
            for(int i=0;i<v[node].size();i++){
                  ll nd = v[node][i].first;
                  P np =v[node][i].second;
                  d[np]=min(d[np],nd);
                  q.push({d[np],np});
            }
      }
      cout<<ans<<endl;

      return 0;
}
