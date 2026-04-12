#include <bits/stdc++.h>
using namespace std;
template<class T> inline void chmax(T& a, T b){if(a<b)a=b;}
template<class T> inline void chmin(T& a, T b){if(a>b)a=b;}
const long long INF = 1LL << 60;

int N;
int a[3100];
bool ischecked[3100][3100] = {false};
long long int dp[3100][3100] = {0};

long long int rec(int L,int R){
  if(L > R) return 0;
  if(ischecked[L][R]) return dp[L][R];
  ischecked[L][R] = true;
  int turn = N - (R - L + 1);
  long long int ret = 0;
  if(turn % 2 == 0){ // 先攻は最大化
    ret = -INF;
    chmax(ret, rec(L+1,R)+a[L]); //左端を取ったら最大か？
    chmax(ret, rec(L,R-1)+a[R]); //右端を取ったら最大か？
  } else { // 後攻は最小化
    ret = INF;
    chmin(ret, rec(L+1,R)-a[L]);
    chmin(ret, rec(L,R-1)-a[R]);
  }
  
  return dp[L][R] = ret;
}
      
      

int main(){
  cin >> N;
  for(int i=0;i<N;++i) cin >> a[i];
  
  cout << rec(0,N-1) << endl;
  return 0;
}