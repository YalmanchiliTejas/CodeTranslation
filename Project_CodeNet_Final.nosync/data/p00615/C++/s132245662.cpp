#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n,m;

  while(cin>> n>>m && (n||m)){
    vector<int> v;
    int tmp;
    for(int i=0;i<n;i++){
      cin >> tmp;
      v.push_back(tmp);
    }
    for(int i=0;i<m;i++){
      cin >> tmp;
      v.push_back(tmp);
    }
    v.push_back(0);

    sort(v.begin(),v.end());

    int ans = 0;
    for(int i=0;i<(int)v.size()-1;i++){
      ans = max(ans,v[i+1]-v[i]);
    }
    cout << ans << endl;
  }
}