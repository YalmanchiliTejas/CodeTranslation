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
    vector<string> s(N);
    REP(i,N) cin>>s[i];

    string ans;
    for(char c='a';c<='z';c++){
        int Min=100;
        REP(i,N) Min=min(Min,(int)count(ALL(s[i]),c));
        REP(i,Min) ans+=c;
    }
    cout<<ans<<endl;

}
