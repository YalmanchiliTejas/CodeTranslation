/*
created on 22/4/2020
*/
#include<bits/stdc++.h>
using namespace std;
#define Endl '\n'
typedef long long int lli;
void solve();
int main(int argc, char const *argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
int const maxlen = 3005;
lli N;
lli arr[maxlen];
lli memo[maxlen][maxlen][2];
lli find_ans(int i, int j, int cur){
  if(i>j){
    return 0;
  }
  lli& ret = memo[i][j][cur];
  if(ret!=-1)
    return ret;
  if(cur == 1){
    ret= min(-arr[i] + find_ans(i+1, j, 0), -arr[j] + find_ans(i, j-1, 0));
  }else {
    ret= max(arr[i] + find_ans(i+1, j, 1), arr[j] + find_ans(i, j-1, 1));
  }
  return ret;
}
void solve(){
  cin>>N;
  memset(memo, -1, sizeof memo);
  for(int i=0;i<N;i++)
    cin>>arr[i];
  lli ans = find_ans(0, N-1,0);
  cout<<ans<<Endl;
}
