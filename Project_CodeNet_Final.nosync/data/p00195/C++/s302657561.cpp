#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int a,b;
  while(1){
    cin>>a>>b;
    if(a==0&&b==0)break;
    int sum=a+b;
    char ans='A';
    rep(i,4){
      cin>>a>>b;
      if(sum<a+b){
        sum=a+b;
        ans='A'+i+1;
      }
    }
    cout<<ans<<" "<<sum<<endl;
  }
}