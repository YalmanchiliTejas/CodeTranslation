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

    vector<bool> row(H,false);
    vector<bool> col(H,false);
    REP(i,H) REP(j,W){
        if(a[i][j]=='#'){
            row[i]=col[j]=true;
        }
    }
    
    REP(i,H){
        if(!row[i]) continue;
        REP(j,W){
            if(!col[j]) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }

}
