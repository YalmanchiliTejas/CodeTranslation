#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<map<char, int>> v;
  
  int n;
  cin >> n;
  
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    
    map<char, int> mp;
    
    for(char c: s){
      mp[c]++;
    }
    
    v.push_back(mp);
    
  }
  
  map<char, int> tmp = v[0];
  
  for(auto p: v){
    for(auto itr = tmp.begin(); itr != tmp.end(); itr++){
      if(itr->second > 0){
        tmp[itr->first] = min(tmp[itr->first], p[itr->first]);
      }
    }
  }
  
  for(auto itr = tmp.begin(); itr != tmp.end(); itr++){
    for(int i=0; i< itr-> second; i++){
      cout << itr -> first;
    }
  }
  cout << endl;
}