#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int n; cin >> n;
  vector<string> v(n);
  rep(i, n) {
    cin >> v[i];
    sort(v[i].begin(), v[i].end());
  }
  map<char, int> ans;
  for(int i = 0; i < v[0].size(); i++){
    ans[v[0].at(i)]++;
  }
  for(int i = 1; i < n; i++){
    map<char, int> t;
    for(int j = 0; j < v[i].size(); j++){
      t[v[i].at(j)]++;
    }
    for(auto itr = ans.begin(); itr != ans.end(); itr++){
      if(t[itr->first] < ans[itr->first]){
        ans[itr->first] = t[itr->first];
      }
    }
  }
  for(auto  itr = ans.begin(); itr != ans.end(); itr++){
    for(int j = 0; j < itr->second; j++){
      cout << itr->first;
    }
  }
  cout << endl;
  system("pause");
}