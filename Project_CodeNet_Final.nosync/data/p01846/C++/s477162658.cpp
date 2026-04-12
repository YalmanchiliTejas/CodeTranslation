#include<bits/stdc++.h>
#define inf 1<<29
#define linf 1e18
#define eps (1e-8)
#define mod 1000000007
#define pi M_PI
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

int main()
{
  string s;
  int a,b,c,d;

  while(1){
    cin>>s;
    if(s=="#")break;
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    bool grid[10][10]={};
    int y=0,x=0;
    FOR(k,0,s.length()){
      if(s[k]=='b'){
        grid[y][x]=true;
        x++;
      }
      else if(s[k]=='/'){
        y++;
        x=0;
      }
      else x+=(s[k]-'0');
    }
    swap(grid[a][b],grid[c][d]);
    string ans="";
    FOR(i,0,y+1){
      int space=0;
      FOR(j,0,x+1){
        if(grid[i][j]){
          if(space!=0)ans+=space+'0';
          ans+="b";
          space=0;
        }
        else space++;
      }
      space--;
      if(0<space)ans+=space+'0';
      if(i!=y)ans+="/";
    }
    cout<<ans<<endl;
  }
        
  return 0;
}