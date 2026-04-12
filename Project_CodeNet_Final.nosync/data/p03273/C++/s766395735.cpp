#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int H,W; cin>>H>>W;
    vector<string> a(H);
    REP(i,H) cin>>a[i];

    set<int> sti;
    REP(i,H){
        bool all=true;
        REP(j,W)
            if(a[i][j]!='.') all=false;
        if(all) sti.insert(i);
    }
    set<int> stj;
    REP(j,W){
        bool all=true;
        REP(i,H)
            if(a[i][j]!='.') all=false;
        if(all) stj.insert(j);
    }

    REP(i,H){
        if(sti.count(i)) continue;
        REP(j,W){
            if(stj.count(j)) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }

}
