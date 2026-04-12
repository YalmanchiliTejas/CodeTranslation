#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>

#define INF 9999999999
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define MOD(x) (x%(mod))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int>pi;

/*---------------------------------------------------*/

int main(){
  int a,b,c,ans;
  cin>>a>>b>>c;
  ans=a*100+b*10+c;
  if(ans%4==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
