#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
 
using namespace std;
 
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
 
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
 
ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}
 
int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}



int main(){
  int N,M;
  cin >> N >> M;
  int perm[10];
  rep(i,10) perm[i] = i+1;
  vector<int> G[100];
  
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 0;
  do{
    bool f = true;
    int to = 0;
    rep(i,N-1){
      auto res = find(all(G[to]),perm[i]);
      if(res == G[to].end()){
	f = false;
	break;
      }
      else{
	to = perm[i];
      }
    }
    // cout << to << " ";
    // rep(i,N-1) cout << perm[i];
    // cout << endl;
    if(f) ans++;
  }while(next_permutation(perm,perm+N-1));
  cout << ans << endl;
}

  
                           

                                                          




