#include <iostream>
using namespace std;

int count_num(string t, char moji){
  int count = 0;
  for (int i = 0; i<t.length(); i++){
    if (t[i] == moji) count += 1;
  }
  return count;
}
int main(void){
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  int N;
  cin >> N;
  string s[N];
  for (int i = 0; i< N; i++){
    cin >> s[i];
  }
  long count;
  long count_total = 0;
  int alpha_count;
  char mojiretsu;
  string ans;
  for (int i = 0; i<26; i++){
    alpha_count = 51;
    mojiretsu = alpha[i];
    for (int j = 0; j<N; j++){
      //cout << "count_num(s[j], alpha[i]) " << count_num(s[j], mojiretsu) << endl;
      alpha_count = min(alpha_count, count_num(s[j], mojiretsu));
    }
    for (int k = 0; k<alpha_count; k++) ans+= mojiretsu;                
  }
  cout << ans << endl;
}