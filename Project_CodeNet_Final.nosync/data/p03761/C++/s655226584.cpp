#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int N; cin>>N;
    vint cnt(26,1e9);
    REP(i,N){
        string s; cin>>s;
        REP(j,26){
            cnt[j]=min(cnt[j],(int)count(ALL(s),'a'+j));
        }
    }
    string ans;
    REP(i,26){
        REP(j,cnt[i]) ans+='a'+i;
    }
    cout<<ans<<endl;
}
