#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef map<int,int> M;
typedef vector<int> V;
typedef queue<int> Q;
typedef pair<long,long> PLL;
typedef map<long,long> MLL;
typedef vector<long> VLL;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define inf 999999
#define EPS (1e-7)
#define MOD (1e9+7)
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define ALL(a)  a.begin(),a.end()
#define RALL(a) a.begin(),a.end(),greater<int>()
#define ROT(a) a.begin(),a.begin()+1,a.end()
#define RROT(a) a.begin(),a.end()-1,a.end()
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
/*--------------------------------------------*/
/*--------------------------------------------*/

int main(){
    int h,w;cin>>h>>w;
    vector<vector<char>> m(101,vector<char>(101));
    rep(i,h){
        rep(j,w){
            cin>>m[i][j];
        }
    }
    V wflag(101,0),hflag(101,0);
    rep(i,h){
        int flag=1;
        rep(j,w){
            if(m[i][j]=='#')flag=0;
        }
        if(flag){wflag[i]++;
        //printf("i,wf=%d,%d\n",i,wflag[i]);
        }
    }
    rep(i,w){
        int flag=1;
        rep(j,h){
            if(m[j][i]=='#')flag=0;
        }
        if(flag){hflag[i]++;
        //printf("i,hf=%d,%d\n",i,hflag[i]);
        }
    }
 
    rep(i,h){
        if(wflag[i])continue;   
        rep(j,w){
            if(hflag[j]){
                //printf("wflag,hflag=%d,%d\n",wflag[i],hflag[j]);
                
                continue;
            }
            cout<<m[i][j];
        }
        cout<<endl;
    }
}
