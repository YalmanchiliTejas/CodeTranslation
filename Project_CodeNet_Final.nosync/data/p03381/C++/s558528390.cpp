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
    vector<pint> a(N);
    REP(i,N){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(ALL(a));

    vint ans(N);
    REP(i,N){
        if(i<N/2) ans[a[i].second]=a[N/2].first;
        else ans[a[i].second]=a[N/2-1].first;
    }
    REP(i,N) cout<<ans[i]<<endl;
}
