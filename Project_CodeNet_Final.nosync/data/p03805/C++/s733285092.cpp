#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  map<int, queue<int>> side;
  for (int i = 0; i < M; i++) {
    int a,b;
    cin >> a >> b;
    side[a].push(b);
    side[b].push(a);
  }
  
  stack<int> path;
  set<int> visit;
  path.push(1);
  visit.insert(1);
  int count = 0;
  
  for (int i = 2; i <= N; i++) {
    if (N > 7) {
      int s1s = side.at(1).size();
      for (int x = 0; x < s1s; x++) {
        int y = side.at(1).front();
        if (i == y) {
          visit.insert(y);
          if (visit.size() == 2) path.push(y);
          break;
        }
        else {
          side.at(1).pop();
          side.at(1).push(y);
        }
      }
      if (visit.size() != 2) continue;
    }
    
    for (int j = 2; j <= N; j++) {
      if (N > 6) {
        int jj = path.top();
        int sjjs = side.at(jj).size();
        for (int x = 0; x < sjjs; x++) {
          int y = side.at(jj).front();
          if (j == y) {
            visit.insert(y);
            if (visit.size() == N - 5) path.push(y);
            break;
          }
          else {
            side.at(jj).pop();
            side.at(jj).push(y);
          }
        }
        if (visit.size() != N - 5) continue;
      }
      
      for (int k = 2; k <= N; k++) {
        if (N > 5) {
          int kk = path.top();
          int skks = side.at(kk).size();
          for (int x = 0; x < skks; x++) {
            int y = side.at(kk).front();
            if (k == y) {
              visit.insert(y);
              if (visit.size() == N - 4) path.push(y);
              break;
            }
            else {
              side.at(kk).pop();
              side.at(kk).push(y);
            }
          }
          if (visit.size() != N - 4) continue;
        }
        
        for (int l = 2; l <= N; l++) {
          if (N > 4) {
            int ll = path.top();
            int slls = side.at(ll).size();
            for (int x = 0; x < slls; x++) {
              int y = side.at(ll).front();
              if (l == y) {
                visit.insert(y);
                if (visit.size() == N - 3) path.push(y);
                break;
              }
              else {
                side.at(ll).pop();
                side.at(ll).push(y);
              }
            }
            if (visit.size() != N - 3) continue;
          }
          
          for (int m = 2; m <= N; m++) {
            if (N > 3) {
              int mm = path.top();
              int smms = side.at(mm).size();
              for (int x = 0; x < smms; x++) {
                int y = side.at(mm).front();
                if (m == y) {
                  visit.insert(y);
                  if (visit.size() == N - 2) path.push(y);
                  break;
                }
                else {
                  side.at(mm).pop();
                  side.at(mm).push(y);
                }
              }
              if (visit.size() != N - 2) continue;
            }
            
            for (int n = 2; n <= N; n++) {
              if (N > 2) {
                int nn = path.top();
                int snns = side.at(nn).size();
                for (int x = 0; x < snns; x++) {
                  int y = side.at(nn).front();
                  if (n == y) {
                    visit.insert(y);
                    if (visit.size() == N - 1) path.push(y);
                    break;
                  }
                  else {
                    side.at(nn).pop();
                    side.at(nn).push(y);
                  }
                }
                if (visit.size() != N - 1) continue;
              }
              
              for (int o = 2; o <= N; o++) {
                int oo = path.top();
                int soos = side.at(oo).size();
                for (int x = 0; x < soos; x++) {
                  int y = side.at(oo).front();
                  if (o == y) {
                    visit.insert(y);
                    if (visit.size() == N) path.push(y);
                    break;
                  }
                  else {
                    side.at(oo).pop();
                    side.at(oo).push(y);
                  }
                }
                if (visit.size() == N) {
                  count++;
                  visit.erase(o);
                  path.pop();
                }
              }
              
              if (N < 3) break;
              if (visit.size() == N - 1) {
                visit.erase(n);
                path.pop();
              }
            }
            if (N < 4) break;
            if (visit.size() == N - 2) {
              visit.erase(m);
              path.pop();
            }
          }
          if (N < 5) break;
          if (visit.size() == N - 3) {
            visit.erase(l);
            path.pop();
          }
        }
        if (N < 6) break;
        if (visit.size() == N - 4) {
          visit.erase(k);
          path.pop();
        }
      }
      if (N < 7) break;
      if (visit.size() == N - 5) {
        visit.erase(j);
        path.pop();
      }
    }
    if (N < 8) break;
    if (visit.size() == 2) {
      visit.erase(i);
      path.pop();
    }
  }
  
  cout << count << endl;
  return 0;
}
