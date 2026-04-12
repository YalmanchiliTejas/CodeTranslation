#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

ll dfs(int n, ll x) {
  if (n == 0) return 1; 
  ll len = (1LL<<(n+1)) - 3;//n-1レベルのバーガーの高さ
  ll num = (1LL<<n)-1;//n-1レベルのバーガーのパテ数
  if(x == 1)return 0;
  else if(x <= len+1)return dfs(n-1,x-1);
  else if(x == len+2)return num+1;
  else if(x <= (len+1)*2)return num+1+dfs(n-1,x-len-2);
  else return num*2+1;
}

int main(){
  int n;
  ll x;
  cin >> n >> x;
  cout << dfs(n, x) << endl;
  return 0;
} 