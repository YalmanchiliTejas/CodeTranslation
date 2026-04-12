#include<bits/stdc++.h>
#define fi first
#define se second
#define show(x) cerr<<#x<<"="<<x<<"\n"
typedef long long ll;
using namespace std;
//const ll MOD=(ll)1e9+7;
//const ll inf=(ll)1e14;
const int dy[]={1,0,-1};
const int dx[]={1,0,-1};
int n,m,h,w;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
  FILE *stream1;
  //FILE *stream2;
  stream1=freopen("in","r",stdin);
  //stream2=freopen("out","w",stdout);
  if(stream1==NULL)return 0;
  //if(stream2==NULL)return 0;
#endif
  for(;;){
    int a[10][10];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)a[i][j]=0;
    string s;cin>>s;
    if(s=="#")exit(0);
    int x1,y1,x2,y2;
    cin>>y1>>x1>>y2>>x2;
    y1--;x1--;y2--;x2--;
    int h=0,w=0;
    for(int i=0;i<(int)s.size();i++){
      if(s[i]=='/'){h++;w=0;continue;}
      if(s[i]=='b'){
        a[h][w]++;
        w++;
      }else{
        int noww=s[i]-'0';
        for(int j=0;j<noww;j++){
          w++;
        }
      }
    }
    h++;
    a[y1][x1]--;
    a[y2][x2]++;
    string ans="";
    for(int i=0;i<h;i++){
      int now=0;
      for(int j=0;j<w;j++){
        if(a[i][j]==1){
        if(now!=0){ans+=to_string(now);now=0;}
        ans+='b';
      }else{
          now++;
        }
      }
      if(now!=0)ans+=to_string(now);
      ans+='/';
    }
    cout<<ans.substr(0,ans.size()-1)<<endl;
  }
#ifdef LOCAL_DEFINE
  cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
  fclose(stream1);
  //fclose(stream2);
#endif
  return 0;
}





