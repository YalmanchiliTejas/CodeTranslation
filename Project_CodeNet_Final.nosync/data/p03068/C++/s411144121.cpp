#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n;
  string s;
  cin >> s;
  cin >> k;
  int moji=s[k-1];
  for(int i=0;i<n;++i){
    if(s[i]==moji){
      cout << s[i];
    }else{
      cout << '*';
    }
  }
  cout << endl;
  return 0;
}
