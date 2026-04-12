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
const int MOD = 1000000007;

// vector<p> cut(M);
// cut[i].second
// cut[i].first;
// REP(i,M){
//     int a,b;cin>>a>>b;
//     cut[i] = make_pair(b,a);//last first の順番
// }
// for(int i=0; i<N;i++){
// }
// sort(cut.begin(),cut.end()); //sort
// char '' str ""
int main(void)
{
    int N;cin>>N;
    str S[50];
    int cnt[50][26];
    int ans[26];
    for(int i=0; i<N;i++){
      cin>>S[i];
    }
    for(int i=0; i<N;i++){
for(int j=0; j<26;j++){
   cnt[i][j]=0;
  }
}
    for(int i=0; i<N;i++){
      for(int j=0; j<S[i].size();j++){
        cnt[i][S[i][j]-'a']++;
      }
    }

    for(int j=0; j<26;j++){
       ans[j] = cnt[0][j];
    }

    for(int i=0; i<N;i++){
      for(int j=0; j<26;j++){
        ans[j] = min(ans[j], cnt[i][j]);
      }
    }
    for(int j=0; j<26;j++){
      for(int i=0; i<ans[j];i++){
        cout<<char(j+'a');
      }
    }

    cout<<endl;
    return 0;
}
