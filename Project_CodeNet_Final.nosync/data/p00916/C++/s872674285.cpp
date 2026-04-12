#include <bits/stdc++.h>

using namespace std;

int l[55], t[55], r[55], b[55];
vector<int> x;
vector<int> y;
int sum[1010][1010];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void compress(int n)
{
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  for(int i = 0; i < n; i++){
    l[i] = find(x.begin(), x.end(), l[i]) - x.begin();
    t[i] = find(y.begin(), y.end(), t[i]) - y.begin();
    r[i] = find(x.begin(), x.end(), r[i]) - x.begin();
    b[i] = find(y.begin(), y.end(), b[i]) - y.begin();
  }
}

void dfs(int yy, int xx)
{
  sum[yy][xx] = 1;
  for(int i = 0; i < 4; i++){
    int nx = xx + dx[i], ny = yy + dy[i];
    if(0 <= nx && nx < x.size() && 0 <= ny && ny < y.size() && sum[ny][nx] == 0) dfs(ny, nx);
  }
}

int main()
{
  int n;
  while(cin >> n, n){
    x.clear();
    y.clear();
    for(int i = 0; i < n; i++){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      l[i] = l[i]*2;
      t[i] = t[i]*2;
      r[i] = r[i]*2;
      b[i] = b[i]*2;
      x.push_back(l[i]-1); y.push_back(t[i]-1);      
      x.push_back(l[i]);   y.push_back(t[i]);
      x.push_back(l[i]+1); y.push_back(t[i]+1);
      x.push_back(r[i]-1); y.push_back(b[i]-1);      
      x.push_back(r[i]);   y.push_back(b[i]);
      x.push_back(r[i]+1); y.push_back(b[i]+1);            
    }
    compress(n);
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < n; i++){
      for(int j = t[i]; j >= b[i]; j--) sum[j][l[i]] = sum[j][r[i]] = 1;
      for(int j = l[i]; j <= r[i]; j++) sum[t[i]][j] = sum[b[i]][j] = 1;
    }    
    int ans = 0;
    for(int i = 0; i < y.size(); i++){
      for(int j = 0; j < x.size(); j++){
	if(sum[i][j] == 0){
	  ans++;
	  dfs(i, j);
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}