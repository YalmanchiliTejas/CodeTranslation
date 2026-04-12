#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> v(26, 100);
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    vector<int> res(26, 0);
    for(int j = 0; j < s.size(); j++){
      for(int k = 0; k < 26; k++){
        if(s[j] == k +97){ res[k]++; break;}
      }
    }
    for(int j = 0; j < 26; j++){
      if(res[j] < v[j]){v[j] = res[j];}
    }
  }

  for(int i = 0; i < 26; i++){
    if(v[i] == 100){ v[i] = 0;}
    while(v[i] > 0){
      char c = i + 97;
      cout << c;
      v[i]--;
    }
  }

  cout << endl;



}       