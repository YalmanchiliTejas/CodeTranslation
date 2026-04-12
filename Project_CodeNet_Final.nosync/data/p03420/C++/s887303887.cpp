#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<bitset>
#include<algorithm>
#include<functional>
#include<climits>
#include<utility>
#include <iomanip>
#include<map>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define REP(i,x) FOR(i,0,x)
#define CLR(a) memset((a), 0 ,sizeof(a))

const ll MOD = 1e+9+7;
const double PI  = acos(-1.0);


int main(){
  ll n,k;
  cin>>n>>k;
  ll ret=0;
  for(int i=k+1;i<=n;i++){
    ret += max(0,((n+1)%i)-k);
    ret += (i-k)*((n+1)/i);
    if(k==0) ret-=1;
  }
  cout<<ret<<"\n";
}
