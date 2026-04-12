#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#define rep(i,n) for(int i=0;i<n;i++)
#define fr(i,c) for(__typeof (c.begin()) i=c.begin(); i!=c.end(); i++)
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

int main(){
  ll a,b,c,d,e,f;
  while(cin>>a>>b>>c>>d>>e>>f,a||b||c||d||e||f){
      ll ans=0;
      a+=d; b+=e; c+=f;
      rep(i,min(min(a,10ll),min(b,c))+1){
        ans=max(ans,(a-i)/3+(b-i)/3+(c-i)/3+i+
        +min((a-i)%3,min((b-i)%3,(c-i)%3)));
      }
      cout<<ans<<endl;
  }
  return 0;
}