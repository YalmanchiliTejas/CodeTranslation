#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

  int n,m;
  while(cin >> n >> m && n+m){
    vector<int> V;
    for(int i = 0; i < n+m; i++){
      int in;
      cin >> in;
      V.push_back(in);
    }
    sort(V.begin(),V.end());
    int time = V[0];
    for(int i = 0; i < V.size()-1; i++) time = max(time,V[i+1]-V[i]);
    cout << time << endl;
  }
  return 0;
}