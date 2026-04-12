#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define scs(x) scanf("%s",x)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
#define memc(x,y) memcpy(&x,&y,sizeof(x))
#define mems(x,y) memset(x,y,sizeof(x))
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define rep(i,v) for(int i=0;i<v;i++)
#define repe(i,v) for(int i=0;i<=v;i++)
#define Rep(i,x,v) for(int i=x;i<v;i++)
#define Repe(i,x,v) for(int i=x;i<=v;i++)
#define repv(i,x) for(auto i=x.begin();i!=x.end();i++)
#define reprv(i,x) for(auto i=x.rbegin();i!=x.rend();i++)
#define dbg(x) cout << #x << " : " << x << endl
#define pb push_back
#define bl putchar('\n')
#define gcc getchar()
#define pcc putchar
#define si size
#define fi first
#define se second
#define MAX 300000
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
using namespace std;

long long int cm_sum[MAX] = {0};
long long int MM=1000000000+7;

int main(){
  // fli();
  int n;
  long long int a[MAX];
  long long int ans = 0;
  mems(cm_sum, 0);
  sc(n);
  rep(i,n){
    cin>>a[i];
    if(i){
      cm_sum[i] = (cm_sum[i-1] + a[i]) % MM;
      ans += (cm_sum[i-1]%MM * a[i]%MM) % MM;
      ans%=MM;
      // cout<<(cm_sum[i-1]) << " with " << a[i] << " : "<<((cm_sum[i-1]%MM * a[i]%MM) % MM)<<endl;
    }else{
      cm_sum[i] = a[i];
    }
  }
  // bl;
  // rep(i,n){
  //   cout<<cm_sum[i]<<' ';
  // }
  // bl;

  cout<<ans<<endl;
  return 0;
}
