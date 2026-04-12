#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef map<int,int> M;
typedef vector<int> V;
typedef queue<int> Q;
typedef pair<long,long> PLL;
typedef map<long,long> MLL;
typedef vector<long long> VLL;
typedef vector<pair<int,int>> VP;
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
int main(){
    int x,y,z;cin>>x>>y>>z;
    x-=z;
    int cnt=0;
    while(1){
        if(x-(y+z)<0)break;
        x-=y+z;
        cnt++;
    }
    cout<<cnt<<endl;
}
