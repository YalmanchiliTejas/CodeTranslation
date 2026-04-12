


#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

 int main(){

  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;

  int ans = 1e9;

  for(int i=0;i<=max(x,y);i++){
      int cnt = 2*i*c+max(x-i,0)*a+max(y-i,0)*b;
      ans = min(ans,cnt);
  }

  cout<<ans<<endl;

 return 0;
 }