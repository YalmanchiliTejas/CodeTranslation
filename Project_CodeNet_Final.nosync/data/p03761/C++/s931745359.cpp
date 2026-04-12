#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int n;
  cin >> n;
  string S;
  cin >> S;
  map<char, int> m;
  for(int i = 0; S[i] != '\0'; i++){
    if(m.count(S[i])){
      m[S[i]]++;
    }else{
      m[S[i]] = 1;
    }
  }
  
  for(int j = 1; j < n; j++){
    map<char, int> ms;
    cin >> S;
    sort(S.begin(), S.end());
    for(int i = 0; S[i] != '\0'; i++){
      if(m.count(S[i])){
        if(ms.count(S[i])){
          if(m[S[i]] > ms[S[i]]) ms[S[i]]++;
        }else{
          ms[S[i]] = 1;
        }
      }
    }
    m = ms;
  }
  
  for(auto i = m.begin(); i != m.end(); i++){
    for(int j = 0; j < i->second; j++){
      cout << i->first;
    }
  }
  cout << endl;
  return 0;
}