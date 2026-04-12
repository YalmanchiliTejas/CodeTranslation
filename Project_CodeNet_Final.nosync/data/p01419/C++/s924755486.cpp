#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

struct aa {
  int x;
  int y;
  int time;
  vector<int>xs;
  vector<int>ys;
};
class Compare {
public:
  //aaが昇順に並ぶ
  bool operator()(const aa&l, const aa&r) {
    return l.time> r.time;
  }
};
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
aa getway(const int fx,const int fy,const int tx,const int ty, const vector<vector<int>>&cans){
  priority_queue<aa, vector<aa>, Compare>que;
  que.push(aa{ fx,fy,0,{},{} });
  int memo[100][100];
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      memo[i][j] = 99999999;
    }
  }
  memo[fy][fx] = 0;
  while (!que.empty()) {
    aa atop(que.top());
    que.pop();
    if (atop.x == tx&&atop.y == ty)return atop;
    else {
      atop.xs.push_back(atop.x);
      atop.ys.push_back(atop.y);
    }
    vector<int> axs(atop.xs);
    vector<int> ays(atop.ys);
    for (int i = 0; i < 4; ++i) {
      int newx = atop.x + dx[i];
      int newy = atop.y + dy[i];
      if (cans[newy][newx]) {
        if (memo[newy][newx]>atop.time + 1) {
          memo[newy][newx] = atop.time + 1;
          que.push(aa{ newx,newy,atop.time + 1,atop.xs,atop.ys });
        }
      }
    }
  }
  assert(false);
}

int main() {
  
  /*int N; cin >> N;
  vector<int>as;
  vector<int>num(10001);
  for (int i = 0; i < N; ++i) {
    int a; scanf("%d", &a);
    num[a]++;
  }
  vector<long long int>nums;
  for (int i = 0; i < 10001; ++i) {
    if (num[i] > 1) {
      string st(to_string(i)+to_string(i));
      nums.push_back(stoll(st));
      if (num[i] >= 3) {
        nums.push_back(stoi(st));
        nums.push_back(stoi(st));
      }
    }
    else if (num[i]) {
      for (int j = 0; j < 10001; ++j) {
        if (i == j)continue;
        if (num[j]) {
          int atime = min(3,num[i] * num[j]);
          string st(to_string(i) + to_string(j));
          for (int i = 0; i < atime; ++i) {

            nums.push_back(stoll(st));
          }
        }
      }
    }
  }
  for (int i = 0; i < 2; ++i) {

    auto it = min_element(nums.begin(), nums.end());
    nums.erase(it);
  }
  auto it = min_element(nums.begin(), nums.end());
  cout << *it << endl;
  return 0;*/
  
  int W, H, M; cin >>H>>W >> M;
  vector<vector<int>>pers(H+2, vector<int>(W+2));
  vector<vector<int>>ons(H + 2, vector<int>(W + 2));
  vector<vector<int>>offs(H + 2, vector<int>(W + 2));
  vector<vector<int>>cans(H + 2, vector<int>(W + 2));
  for (int i = 1; i <= H; ++i) {
    string st; cin >> st;
    for (int j = 1; j <= W; ++j) {
      if (st[j - 1] == '.') {
        cans[i][j] = true;
      }
    }
  }
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      int per; cin >> per;
      pers[i][j] = per;
    }
  }
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      int per; cin >> per;
      ons[i][j] = per;
    }
  }
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      int per; cin >> per;
      offs[i][j] = per;
    }
  }
  int fx, fy; cin >> fy >> fx;
  fx++; fy++;
  vector<int>xmoves;
  vector<int>ymoves;
  for (int i = 0; i < M-1; ++i) {
    int tx, ty; cin >> ty >> tx; tx++; ty++;
    aa ways= getway(fx, fy, tx, ty,cans);
    xmoves.insert(xmoves.end(), ways.xs.begin(), ways.xs.end());
    ymoves.insert(ymoves.end(), ways.ys.begin(), ways.ys.end());
    fx = tx; fy = ty;
    if (i == M - 2) {
      xmoves.push_back(tx);
      ymoves.push_back(ty);
    }
  }
  vector<vector<vector<int>>>times(H + 2, vector<vector<int>>((W + 2), vector<int>()));
  for (int i = 0; i < xmoves.size(); ++i) {
    times[ymoves[i]][xmoves[i]].push_back(i);
  }
  long long int ans = 0;
  for (int i =1; i < H + 1; ++i) {
    for (int j = 1; j < W + 1; ++j) {
      long long int cost = 0;
      vector<int>ntimes(times[i][j]);
      if (!ntimes.empty()) {
        cost += ons[i][j]+offs[i][j];
        for (int k = 0; k < ntimes.size() - 1; ++k) {
          int byetime = ntimes[k + 1] - ntimes[k];
          cost += min(byetime*pers[i][j], ons[i][j] + offs[i][j]);
        }
      }
      
      ans += cost;
    }
  }
  cout << ans << endl;
  return 0;
}