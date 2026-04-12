#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define sa(a,n,t) for(int ii=0;ii<n;ii++) scanf("%"#t"",&(a)[ii])
#define rep(i,n) for(int i=0;i<n;i++) 
#define reps(i,a,n) for(int i=a;i<n;i++) 
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rreps(i,a,n) for(int i=n-1;i>=a;i--)
#define validl(i,a,b) ((i>=a)&&(i<=b))?1:0
#define validmat(x,y,a,b,c,d) (validl(x,a,b) && validl(y,a,b))?1:0
#define validmn(x,y,m,n) validmat(x,y,0,m,0,n)
#define valid(i,n) validl(i,0,n)
#define v(t) vector<t>
#define vv(t) vector<vector<t> >
#define mk make_pair
#define pb push_back
#define pa(a,n,t)  for(int i=0;i<n;i++) printf("%"#t"",a[i])
#define p2 pair<int,int>
#define p3 pair<p2,int>
#define fi first
#define se second
#define sd(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld",a)
#define pd(a) printf("%d",a)
#define sf(a) scanf("%lf",&a)
#define pf(a) printf("%lf",a)
#define nline printf("\n")
#define ss(a) scanf("%s",a)
#define ps(a) printf("%s",a)
#define sc(a) scanf("%c",&a)
#define pc(a) printf("%c",&a)
#define mf(m,f) m.find(f)!=m.end()
#define pp3(m) cout<<m.fi.fi<<" "<<m.fi.se<<" "<<m.se<<" "
#define pp2(m) cout<<m.fi<<" "<<m.se<<" "
#define debug 0
/*v(int) adj[200001];
void dfs(int i,int p){
    rep(j,adj[i].size()){
        if(p!=adj[i][j])
            dfs(adj[i][j],i);
    }
}*/
int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  lli n,x,m;
  lli a[100001]={0};
  lli b[100001]={0};
  lli ans=0;
  cin>>n>>x>>m;
  lli xx=x;
  if(m==1){
      cout<<0<<endl;
      return 0;
  }
  if(n<1000000) {
      rep(i,n){
          ans+=xx;
          xx=(xx*xx)%m;
      }
      cout<<ans<<endl;
      return 0;
  }
  reps(i,1,m+1){
      //cout<<xx<<" ";
      if(i==n+1){
          cout<<ans<<endl;
          return 0;
      }
      if(a[xx]!=0) {
          lli j=i-a[xx];
          //cout<<"i"<<i<<a[xx];
          //cout<<"j"<<j<<" "<<(n-a[xx]+1)<<" "<<ans-b[a[xx]-1]<<" ";
          lli temp=((n-a[xx]+1)/j-1)*(ans-b[a[xx]-1]);
          ans+=temp;
          j=(n-a[xx]+1)%j;
          //cout<<j<<" ";
          rep(k,j){
              ans+=xx;
                xx=(xx*xx)%m;
          }
          cout<<ans<<endl;
          return 0;
      }
      a[xx]=i;
      ans+=xx;
      b[i]=ans;
      xx=(xx*xx)%m;
  }
  return 0;
}