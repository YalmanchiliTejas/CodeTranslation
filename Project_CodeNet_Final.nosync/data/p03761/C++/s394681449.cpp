#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<string> s(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  map<char,int> mp;
  for (int i = 0; i < (int)s[0].size(); i++)
  {
    mp[s[0][i]]++;
  }
  
  for (int i = 1; i < n; i++)
  {
    map<char,int> mps;
    for (int j = 0; j < (int)s[i].size(); j++)
    {
      mps[s[i][j]]++;
    }
    for(auto p:mp){
      mp[p.first] = min(mps[p.first],p.second);
    }
  }

  for(auto p:mp){
    for (int i = 0; i < p.second; i++)
    {
      cout << p.first;
    }
  }
  cout << endl;
}