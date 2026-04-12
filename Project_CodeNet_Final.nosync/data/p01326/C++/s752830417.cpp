#include<bits/stdc++.h>
using namespace std;
string pat[4] = {"0xxxxxxx","110yyyyx10xxxxxx","1110yyyy10yxxxxx10xxxxxx","11110yyy10yyxxxx10xxxxxx10xxxxxx"};
int N;
map< pair< int , bool > , int > used;
vector< string > data;
int rec2( int idx, const string& str, const string& patan, bool y_flag){
  if(idx == str.size()){
    return y_flag;
  }
  int ret = 0;
  if(used.find( make_pair( idx, y_flag)) != used.end()) return used[make_pair( idx, y_flag)];
  if(isdigit(str[idx])){
    if(isdigit(patan[idx])){
      if(str[idx] != patan[idx]) return 0;
      else ret = rec2( idx + 1,  str, patan, y_flag);
    } else {
      ret = rec2( idx + 1, str, patan, y_flag|(str[idx]=='1'&&patan[idx]=='y'));
    }
  } else {
    if(isdigit(patan[idx])){
      ret = rec2( idx + 1, str, patan, y_flag);
    } else {
      ret = rec2( idx + 1, str, patan, y_flag|(patan[idx]=='y')) + rec2( idx + 1, str, patan, y_flag);
    }
  }
  return used[make_pair( idx, y_flag)] = ret % 1000000;
}
int rec( int idx, const string& str, const string& patan, bool y_flag){
  used.clear();
  return rec2( idx, str, patan, y_flag);
}
int main(){
  long long dp[1001] = {};
  while(cin >> N, N){
    for(int i = 0; i < N; i++){
      string s;
      cin >> s;
      data.push_back(s);
    }
    for(int i = 0; i < N; i++){
      if(i == 0){
        dp[i] = rec( 0, data[0], pat[0], true);
        dp[i] %= 1000000;
      } else if(i == 1){
        dp[i] = dp[0] * rec( 0, data[i], pat[0], true);
        dp[i] %= 1000000;
        dp[i] += rec( 0, data[0] + data[1], pat[1], false);
        dp[i] %= 1000000;
      } else if(i == 2){
        dp[i] = dp[1] * rec( 0, data[2], pat[0], true);
        dp[i] %= 1000000;
        dp[i] += dp[0] * rec( 0, data[1] + data[2], pat[1], false);
        dp[i] %= 1000000;
        dp[i] += rec( 0, data[0] + data[1] + data[2], pat[2], false);
        dp[i] %= 1000000;
      } else if(i == 3){
        dp[i] = dp[2] * rec( 0, data[3], pat[0], true);
        dp[i] %= 1000000;
        dp[i] += dp[1] * rec( 0, data[2] + data[3], pat[1], false);
        dp[i] %= 1000000;
        dp[i] += dp[0] * rec( 0, data[1] + data[2] + data[3], pat[2], false);
        dp[i] %= 1000000;
        dp[i] += rec( 0, data[0] + data[1] + data[2] + data[3], pat[3], false);
        dp[i] %= 1000000;
      } else {
        dp[i] = dp[i - 1] * rec( 0, data[i], pat[0], true);
        dp[i] %= 1000000;
        dp[i] += dp[i - 2] * rec( 0, data[i - 1] + data[i], pat[1], false);
        dp[i] %= 1000000;
        dp[i] += dp[i - 3] * rec( 0, data[i - 2] + data[i - 1] + data[i], pat[2], false);
        dp[i] %= 1000000;
        dp[i] += dp[i - 4] * rec( 0, data[i - 3] + data[i - 2] + data[i - 1] + data[i], pat[3], false);
        dp[i] %= 1000000;
      }
    }
    cout << dp[N - 1] << endl;

    data.clear();
  }
}