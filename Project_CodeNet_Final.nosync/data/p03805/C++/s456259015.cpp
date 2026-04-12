#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl
#define POSSIBLE(condition) if(condition){cout << "POSSIBLE" << endl;}else{cout << "IMPOSSIBLE" << endl;}
#define Possible(condition) if(condition){cout << "Possible" << endl;}else{cout << "Impossible" << endl;}
#define possible(condition) if(condition){cout << "possible" << endl;}else{cout << "impossible" << endl;}
#define Size(n) (n).size()

typedef long long ll;


using namespace std;

const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;
const ll LINF = 1e18;


long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl=true,graph[10][10];
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

      
      cin>>n>>m;
      rep(i,m){
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
      }
      vector<ll> p(n-1);
      rep(i,n){
        if(i!=0){
          p[i-1]=i+1;
        }
      }
      //rep(i,n-1)Cout(p[i]);
      do{
        map<ll,ll> mp;
        fl=true;
        if(!graph[1][p[0]])continue;
        rep(i,n-2){
          if(!graph[p[i]][p[i+1]])fl=false;
        }
        if(!fl)continue;
        fl=true;
        rep(i,n-1)mp[p[i]]++;
        mp[1]++;
        rep(i,n){
          if(mp[i+1]!=1)fl=false;
        }
        if(!fl)continue;
        ans++;
      }while(next_permutation(all(p)));
     Cout(ans);

       
return 0;
}
