#include<iostream>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) (c).begin(),(c).end()
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define mp make_pair
#define pb push_back
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf=1<<28;
const double INF=1e12,EPS=1e-9;

int n,m;
char in[99];

int main()
{
  while(scanf("%d%d",&m,&n),m){
    int r=m,c=0; bool a[1000];
    rep(i,m)a[i]=1;

    for(int i=1;i<=n;i++){
      for(;!a[c];c=(c+1)%m);
      scanf("%s",in);
      if(r==1)continue;
      if(i%15==0){
	if(strcmp(in,"FizzBuzz"))a[c]=0,r--;
      }
      else if(i%5==0){
	if(strcmp(in,"Buzz"))a[c]=0,r--;
      }
      else if(i%3==0){
	if(strcmp(in,"Fizz"))a[c]=0,r--;
      }
      else{
	if(!isdigit(in[0])||atoi(in)!=i)a[c]=0,r--;
      }
      c=(c+1)%m;
    }
    bool f=1;
    rep(i,m)if(a[i]){
      if(!f)putchar(' '); else f=0;
      printf("%d",i+1);
    }
    puts("");
  }
  return 0;
}