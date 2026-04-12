#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
  int n, m;
  while(cin >> n >> m, n||m){
    int k = 0, a = n;
    queue<int> players;
    for(int i = 0; i < n; ++i) players.push(i+1);
    for(int i = 1; i <= m; ++i){
      string s, t;
      cin >> s;
      if(i%3 == 0) t += "Fizz";
      if(i%5 == 0) t += "Buzz";
      if(i%3 && i%5) t = to_string(i);
      if(s == t){
        int p = players.front();
        players.pop();
        players.push(p);
      }else{
        if(players.size() > 1){
          players.pop();
        }
      }
    }
    vector<int> ans;
    while(!players.empty()){
      ans.push_back(players.front());
      players.pop();
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    for(int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
    cout << endl;
  }
  return 0;
}

