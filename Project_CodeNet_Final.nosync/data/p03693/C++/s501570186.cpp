#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
#include<map>
#include<set>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int x=0,r,g,b;
  cin>>r>>g>>b;
  x+=r*100+g*10+b;
  if(x%4==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
