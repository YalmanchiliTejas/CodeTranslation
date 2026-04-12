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
#define Size(n) (n).size()

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
//long long int ruizyo(long long int aa, long long int bb){
  //  if(aa==0){
    //    return 1;
    //}
    //else if(aa%2==0){
      //  long long int tt=ruizyo(aa/2,bb);
        //return (tt*tt)%MOD;
    //}
    //else{
      //  return (ruizyo(aa-1,bb)*bb)%MOD;
    //}
//}フェルマ－のア


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

//bool f[100001];//1000000以下の素数を調べよう！
//rrep(i,2,100001){
  //      f[i]=false;
    //}
//rrep(i,2,100001){
  //      if(!f[i]){
    //        for(int j=i+i;j<=100000;j+=i){
      //          f[j]=true;
        //    }
        //}
    //}
    //for(int i=3;i<=100000;i+=2){
      //  if(!f[i]){
        //    c[i]++;
      //  }
   // }

//visited=vector<vector<bool>>(10,vector<bool>(10,false));アを全部falseに


long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl=true,graph[100][100];

int dfs(int now,int nn,bool* visited){
    bool all_visited=true;
    rep(i,nn){
        if(!visited[i]){
            all_visited=false;
        }
    }
    ll tmp=0;
    if(all_visited){
        return 1;
    }
    rep(i,nn){
       if(!graph[now][i]){
           continue;
       }
       if(visited[i]){
           continue;
       }
       visited[i]=true;
       tmp+=dfs(i,nn,visited);
       visited[i]=false;
    }
    return tmp;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

       cin >> n >> m;
       rep(i,m){
           cin>>a>>b;
           graph[a-1][b-1]=graph[b-1][a-1]=true;
       }
       bool visited[100];
       rep(i,101){
           visited[i]=false;
       }
       visited[0]=true;
      Cout(dfs(0,n,visited));
       
return 0;
}
