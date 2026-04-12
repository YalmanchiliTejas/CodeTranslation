#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb pushback
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,j,n) for(int i=j;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)


int main() {
    ll a,b,c,x,y;
    ll ans=0;
	cin >> a>> b>> c>>x>>y;
    if(a+b>2*c){
      ans+=min(x,y)*2*c;
      if(x>y){
        ans+=min(a,2*c)*(x-y);
      }
      else if(y>x){
        ans+=min(b,2*c)*(y-x);
      }
    }
    else ans+=a*x+b*y;
    cout << ans << endl;
}