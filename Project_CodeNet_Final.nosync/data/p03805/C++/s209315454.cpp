#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8;
int n, answer=0, v[1+MAXN];
bool edge[1+MAXN][1+MAXN], seen[1+MAXN];

void Backtracking(int x){
    if(x == n + 1) {
        answer++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!seen[i] && edge[v[x - 1]][i]) {
            v[x] = i;
            seen[i] = true;
            Backtracking(x + 1);
            seen[i] = false;
        }
    }
}

int main() {
  int m;
  answer = 0;
  cin >> n >> m;
  int temp_1, temp_2;
  for(int i = 0; i < m; ++i){
    cin >> temp_1 >> temp_2;
    edge[temp_1][temp_2] = edge[temp_2][temp_1] = true;
  }
  v[1] = 1;
  seen[1] = true; // check point
  Backtracking(2);
  cout << answer << endl;
}
