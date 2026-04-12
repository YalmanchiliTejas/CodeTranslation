#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXD=11;
    int A,B;
    int d[MAXD][MAXD];
    int f[MAXD*MAXD][MAXD*MAXD];
    void solve(){
        cin>>A>>B;
        for(int x=1;x<=A;x++){
            for(int y=1;y<=B;y++)
                cin>>d[x][y];
        }
        for(int x=1;x<=A;x++){
            for(int y=1;y<=B;y++){
                for(int a=0;a<=100;a++){
                    for(int b=0;b<=100;b++){
                        f[a][b]=max(f[a][b],d[x][y]-x*a-y*b);
                    }
                }
            }
        }
        for(int x=1;x<=A;x++){
            for(int y=1;y<=B;y++){
                int mmin=1e9;
                for(int a=0;a<=100;a++){
                    for(int b=0;b<=100;b++){
                        mmin=min(mmin,x*a+y*b+f[a][b]);
                    }
                }
                if(mmin!=d[x][y]){
                    cout<<"Impossible\n";
                    return;
                }
            }
        }
        cout<<"Possible\n";
        cout<<300<<" "<<101*101+298<<"\n";
        for(int u=1;u<150;u++){
            cout<<u<<" "<<u+1<<" "<<'X'<<"\n";
        }
        for(int u=151;u<300;u++){
            cout<<u<<" "<<u+1<<" "<<'Y'<<"\n";
        }
        for(int u=0;u<=100;u++){
            for(int v=0;v<=100;v++){
                cout<<u+1<<" "<<300-v<<"  "<<f[u][v]<<"\n";
            }
        }
        cout<<1<<" "<<300;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}