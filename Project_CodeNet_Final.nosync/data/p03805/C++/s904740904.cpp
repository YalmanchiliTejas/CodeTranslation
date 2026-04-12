#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define P pair<int,int>
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
#define possible(n) cout << ((n) ? "possible" : "impossible"  ) << endl

typedef long long ll;

using namespace std;

const int INF = 1e9,MOD = 1e9 + 7;
const ll LINF = 1e18;

//long long int kaizyo(long long int hh){
  //  cmp=1;
    //while(hh>1){
      //  cmp=(cmp*hh)%MOD;
        //hh--;
    //}
    //return cmp;
//}

//while(x!=0){
            //sum+=x%10;
           // x/=10;
        //}
        //各桁の和

//pair<int,int> p[100000];
//P r[100000];
//cin >> tmp;
//p[i]=make_pair(tmp,i);
//cout << p[i].second+1 << endl;//ペアの右側つまりiを出力

//s.find(w[i])==string::npos
//findの使い方

//for(int i=0;i<n;i++){
   // b[i]=x%2;
    //x/=2;
  //}二進数

long long int n,cnt=0,ans=0,a,b,c,cmp,cmpp,m,h,w,x,y,sum=0;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl=true,graph[100][100];

int dfs(int now,int n,bool* visited){
    bool allvisited=true;
    rep(i,n){
        if(!visited[i]){
            allvisited=false;
        }
    }
    
    if(allvisited){
        return 1;
    }
    
   int pos=0;
    
    rep(i,n){
        if(!graph[now][i]){
            continue;
        }
        if(visited[i]){
            continue;
        }
        visited[i]=true;
        pos+=dfs(i,n,visited);
        visited[i]=false;
    }
    return pos;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

       cin >> n >> m;
       rep(i,m){
           cin >> a >> b;
           graph[a-1][b-1]=true;
           graph[b-1][a-1]=true;
       }
       bool visited[100];
       
       rep(i,n){
           visited[i]=false;
       }
       visited[0]=true;
       Cout(dfs(0,n,visited));
       
return 0;
}
