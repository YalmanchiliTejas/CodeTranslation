#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <cctype>
#include <utility>
#include <climits>


using namespace std;
using ll = long long;
using P = pair<ll,ll>;


const int mod = 1000000007;
const int inf = (1<<30)-1;
const ll linf = (1LL<<62LL)-1;
const double EPS = (1e-10);


#define anyfill(n,s) setw(n) << setfill(s)
#define loop(s) for(int i = 0; s > i; i++)
#define rep(i,q) for(int i = 0; (q) > i; i++)
#define repp(i,n,q) for(int i = n; (q) > i; i++)
#define dep(i,q) for(int i = (q); 0 < i; i--)


#define pb push_back
#define fir first
#define scn second
#define ednl endl


#define YesNo(a) (a?"Yes":"No")
#define YESNO(a) (a?"YES":"NO")
#define yesno(a) (a?"yes":"no")

P ar4[4] = {{0,1},{0,-1},{1,0},{-1,0}};
P ar8[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
long long init[51];
long long niit[51];
long long DFS(long long lv,long long n){
  if(n <= 0)return 0;
  if(init[lv] <= n){
    return niit[lv];
  }
  if(lv==0){
    return 1;
  }
  long long ryo = 0;
  
  n--;
  if(n <= 0)return ryo;
  ryo += DFS(lv-1,n);n-=init[lv-1];
  if(n <= 0)return ryo;
  ryo += 1;n--;
  if(n <= 0)return ryo;
  ryo += DFS(lv-1,n);n-=init[lv-1];
  
  if(n <= 0)return ryo;
  n--;
  return ryo;
  
}
__attribute__((constructor))
void initial() {
 cin.tie(0);
 ios::sync_with_stdio(false);
}
int main(){
  init[0] = 1;
  niit[0] = 1;
  for(int i = 1; 51 > i; i++){
    init[i]=init[i-1]*2+3;
    niit[i]=niit[i-1]*2+1;
  }
  long long n,x;cin>>n>>x;
  cout << DFS(n,x) << endl;
}
