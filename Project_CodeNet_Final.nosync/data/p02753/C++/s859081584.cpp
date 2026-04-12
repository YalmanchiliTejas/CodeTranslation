#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
#define REP(i,j,n) for (int i=j;i<(n);i++)
#define RREP(i,n) for (int i = n; 0<i;i--)
#define print(out) cout<< out  << "\n";
#define mod 1000000007
const int INF = 1e9;
typedef pair<ll,ll> P;

int N,M;
string S;
int main(){
  cin>>S;
  int a=0,b=0;
  REP(i,0,3){
    if(S[i]=="A"[0]){
      a++;
    }
    else b++;
  }
  if((a==3)or(b==3))print("No")
  else print("Yes")

}
