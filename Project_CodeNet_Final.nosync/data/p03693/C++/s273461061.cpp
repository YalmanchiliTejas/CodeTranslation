#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1000000000
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
    int r,g, b;cin>>r>>g>>b;
    int sum = r*100+g*10+b;
    if(sum%4==0){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }

    return 0;
}
