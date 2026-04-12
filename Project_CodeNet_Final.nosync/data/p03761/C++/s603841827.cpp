#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
int main(){
  int n, ans[27], a[27], i, j, k;
  char c;
  string s;
  cin >> n;
  for(i = 0; i < 27; i++){
      ans[i] = 100;
  }
  for(i = 0; i < n; i++){
    cin >> s;
    for(j = 0; j < 27; j++){
      a[j] = 0;
    }
    for(j = 0; j < s.length(); j++){
      for(c = 'a', k = 0; c <= 'z'; c++, k++){
        if(c == s[j]) a[k]++;
      }
    }
    for(j = 0; j < 27; j++){
      ans[j] = (a[j] > ans[j]) ? ans[j] : a[j];
    }
  }
  for(i = 0, c ='a'; c <= 'z'; c++, i++){
    for(j = 0; j < ans[i]; j++) cout << c;
  }
  cout << endl;
}