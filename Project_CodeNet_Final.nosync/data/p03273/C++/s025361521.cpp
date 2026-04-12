#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define rollcall cout<<"I'm Sucu."<<endl;
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl
#define int ll
#define Endl endl


signed main(){
    int H,W;
    char a[104][104];
    cin >>  H >> W;
    REP(i,H){
        REP(j,W){
            cin >> a[i][j];
        }
    }
    REP(i,H){
        bool f=true;
        REP(j,W){
            if(a[i][j]=='#'){
                f=false;
            }
        }
        if(f==true){
            REP(j,W){
                a[i][j]='t';
            }
        }
    }
    REP(j,W){
        bool f=true;
        REP(i,H){
            if(a[i][j]=='#'){
                f=false;
            }
        }
        if(f==true){
            REP(i,H){
                a[i][j]='t';
            }
        }
    }
    REP(i,H){
        bool f=true;
        REP(j,W){
            if(a[i][j]!='t'){
                f=false;
            }
        }
        if(f)continue;
        REP(j,W){
            if(a[i][j]!='t'){
                cout << a[i][j];
            }
        }cout <<endl;
    }cout << Endl;
    
    return 0;
}   
