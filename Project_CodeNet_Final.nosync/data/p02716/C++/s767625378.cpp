#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define endl "\n"
#define F first
#define S second
#define EN cout<<endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;


ll gcd(unsigned a, unsigned b) {

  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
    int n, k;
    cin>>n;
    
    ll a[202020],ans,ans2;
    ll r[2][202020]={};
    cin>>a[0]>>a[1];
    r[0][0]=a[0];r[1][0]=a[1];
    REP(i,2,n){
        cin>>a[i];
        r[i%2][i/2]=a[i]+r[i%2][i/2 -1];
    }
    if(n%2==0){
        ans=r[1][n/2 -1];
        rep(i,n/2){
            MAX(ans,r[0][i]+r[1][n/2 -1]-r[1][i]);
            
        }
        cout<<ans;
    }
    else{
        ans=r[1][n/2 -1];
        ans2=a[0];
        ans=max(ans,r[0][n/2]-a[0]);
        REP(i,1,n/2+1){
            ans=max(ans,r[0][n/2]-a[i*2]);
            ans=max(ans,r[1][i-1]+r[0][n/2]-r[0][i]);
            if(i>=2){
              ans2=max(ans2+a[i*2-1],r[0][i-2]+a[i*2-1]);
              ans=max(ans,ans2+r[1][n/2-1]-r[1][i -1]);
              ans=max(ans,ans2+r[0][n/2]-r[0][i]);
            }
        }
        
        
        cout<<ans;
    }
    EN;
}
