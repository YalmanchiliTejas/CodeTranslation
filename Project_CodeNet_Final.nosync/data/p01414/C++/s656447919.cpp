#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9
const char color_list[] = {'R', 'G', 'B'};

int stamp(int status, const pair<int, int>& stamp, int pos_h, int pos_w, char color, const vector<char>& c){
  int up = max(pos_h, 0);
  int down = min(stamp.first + pos_h, 4);
  int left = max(pos_w, 0);
  int right = min(stamp.second + pos_w, 4);

  int stamp_bit = 0;
  for(int i = up; i < down; i++)
    for(int j = left; j < right; j++)
      stamp_bit |= 1 << ((i * 4) + j);

  for(int i = 0; i < 16; i++){
    if((stamp_bit & (1 << i)) != 0){
      if(color == c[i]){ status |= (1 << i); }
      else{ status &= ~(1 << i); }
    }
  }

  return status;
}

int main(void){
  int n;
  cin >> n;

  int h, w;
  vector<pair<int, int> > stamps;
  for(int i = 0; i < n; i++){
    cin >> h >> w;
    stamps.push_back(make_pair(h, w));
  }
  vector<char> c(16);
  for(int i = 0; i < 16; i++){ cin >> c[i]; }

  
  int ans = INF;
  const int goal = (1 << 16) - 1;

  // テ・ツケツ?・ツ?ェテ・ツ?暗」ツ?凖」ツつ?
  vector<bool> used(1 << 16, false);
  queue<pair<int, int> > wait;
  wait.push(make_pair(0, 0));
  used[0] = true;
  while(!wait.empty()){
    int cost = wait.front().first;
    int status = wait.front().second;
    wait.pop();

    if(status == goal){
      ans = cost;
      break;
    }

    for(int i = 0; i < n; i++){
      for(int z = 0; z < 3; z++){
        for(int x = 1 - stamps[i].first; x < 4; x++){
          for(int y = 1 - stamps[i].second; y < 4; y++){
            int next_status = stamp(status, stamps[i], x, y, color_list[z], c);
            if(!used[next_status]){
              used[next_status] = true;
              wait.push(make_pair(cost + 1, next_status));
            }    
          }
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}