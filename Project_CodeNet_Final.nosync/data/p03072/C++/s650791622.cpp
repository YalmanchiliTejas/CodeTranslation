#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1LL << 60
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const long long MOD=1000000007;

// vector<p> cut(M); vector<vector<ll> > v(4);
// cut[i].second
// cut[i].first;
// REP(i,M){
//     int a,b;cin>>a>>b;
//     cut[i] = make_pair(b,a);//last first の順番
// }
// for(int i=0; i<N;i++){
// }
// sort(cut.begin(),cut.end()), sort(v.rbegin(), v.rend()); //sort
// char '' str ""
int main(void)
{
    int N; cin>>N; int cnt = 0;
    std::vector<int> v;
    for(int i=0; i<N ;i++){
      int h; cin>>h;
      v.push_back(h);
    }
    bool flag=true;
    for(int i=1; i<N ;i++){
      for(int j=0; j<i ;j++){
        if(v[j] > v[i]) flag = false;
      }
      if(flag) cnt++;
      flag = true;
    }

    cout<<cnt+1<<endl;
    return 0;
}
