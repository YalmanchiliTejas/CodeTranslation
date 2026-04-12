#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int l[52], t[52], r[52], b[52];
ll field[150][150];
int H, W;
const int dd[] = {0, 1, 0, -1, 0};

void dfs(int y, int x){
  ll c = field[y][x];
  field[y][x] = -1;
  for(int k=0;k<4;k++){
    int ny = y + dd[k], nx = x + dd[k + 1];
    if(ny < 0 || H <= ny || nx < 0 || W <= nx) continue;
    if(field[ny][nx] == c){
      dfs(ny, nx);
    }
  }
}

int main(){
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;

    set<int> sx, sy;
    for(int i=0;i<n;i++){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      sx.insert(l[i]);
      sx.insert(r[i]);
      sy.insert(t[i]);
      sy.insert(b[i]);
    }

    map<int, int> mx, my;
    W = 1;
    for(int x : sx){
      mx[x] = W++;
    }
    H = 1;
    for(int y : sy){
      my[y] = H++;
    }
  
    for(int i=0;i<n;i++){
      l[i] = mx[l[i]];
      r[i] = mx[r[i]];
      t[i] = my[t[i]];
      b[i] = my[b[i]];
    }

    memset(field, 0, sizeof(field));
    for(int i=0;i<n;i++){
      for(int x=l[i];x<r[i];x++){
	for(int y=b[i];y<t[i];y++){
	  field[y][x] |= (1LL << i);
	}
      }
    }

    int ans = 0;
    for(int y=0;y<H;y++){
      for(int x=0;x<W;x++){
	if(field[y][x] != -1){
	  ans++;
	  dfs(y, x);
	}
      }
    }

    cout << ans << endl;
  }

  return 0;
}