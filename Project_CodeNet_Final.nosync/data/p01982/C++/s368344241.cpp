#include<bits/stdc++.h>
#define MAX 100
#define inf 1<<29
#define linf (1e16)
#define eps (1e-8)
#define Eps (1e-12)
#define mod 1000000007
#define pi acos(-1.0)
#define phi (1.0+sqrt(5.0))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define pld(a) printf("%.10Lf\n",(ld)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main()
{
  int n,l,r,A[MAX];
  while(cin>>n && n){
    cin>>l>>r;
    int ans = 0;
    FOR(i,1,n+1)cin>>A[i];
    FOR(x,l,r+1){
      FOR(i,1,n+1){
        if(x%A[i]==0){
          if(i%2==1)ans++;
          break;
        }
        if(i==n && n%2==0)ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
