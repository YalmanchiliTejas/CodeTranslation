#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string>s(n);
  int i,j;
  for(i=0;i<n;i++){
    cin >> s[i];
  }
  vector<int>alp(26);
  vector<int>alptmp(26);

  for(i=0;i<s[0].length();i++){
    int ss = (int)(s[0][i]-'a');
    alp[ss]++;
  }
  for(i=1;i<n;i++){
    for(j=0;j<26;j++){
      alptmp[j] = 0;
    }
    for(j=0;j<s[i].length();j++){
      int ss = (int)(s[i][j]-'a');
      alptmp[ss]++;
    }
    for(j=0;j<26;j++){
      alp[j] = min(alp[j],alptmp[j]);
    }
  }
  string tmp = "";
  for(i=0;i<26;i++){
    char moji = (char)(i+'a');

    while(alp[i]>0){
      tmp += moji;
      alp[i]--;
    }
  }
  cout << tmp << endl;
}
