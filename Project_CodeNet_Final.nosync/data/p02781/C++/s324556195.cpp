#include <bits/stdc++.h>

using namespace std;
int main(){
  string s;
  long long k;
  cin >> s >> k;
  long long ans=0, tmp=k;
  for(int i=0;i<s.length() && k>0;i++){
    if(s[i]!='0'){
      long long plus=1;
      for(int j=0;j<k;j++){
        plus *= 9*(s.length()-i-1-j);
      }
      for(int j=0;j<k;j++){
        plus /= j+1;
      }
      ans += plus;
      plus=1;
      for(int j=0;j<k-1;j++){
        plus *= 9*(s.length()-i-1-j);
      }
      for(int j=0;j<k-1;j++){
        plus /= j+1;
      }
      ans += (s[i]-'0'-1)*plus;
      k--;
    }
  }
  cout << ans+(k==0?1:0) << endl;
}

