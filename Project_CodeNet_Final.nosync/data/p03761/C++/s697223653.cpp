#include<bits/stdc++.h>
using namespace std;


int main(){
  int min, al[26] = {100}, n;
  string str, ans;

  for(int i=0; i<26; ++i)
    al[i] = 100;
  
  cin >> n;

  for(int i=0; i<n; ++i){
    cin >> str;

    int a[26] = {0};
    for(int k=0; k<str.size(); ++k){
      ++a[str[k]-'a'];
    }

    for(int k=0; k<26; ++k){
      if(al[k] > a[k]){
	al[k] = a[k];
      }
    }
  }

  for(int i=0; i<26; ++i){
    if(al[i] != 100){
      for(int k=0; k<al[i]; ++k){
	ans+= i + 'a';
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}
