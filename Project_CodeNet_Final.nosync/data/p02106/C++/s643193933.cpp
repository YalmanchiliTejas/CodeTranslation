#include<bits/stdc++.h>

using namespace std;

const int backet = 333;

int N, Q;
vector< int > g[100000];
int in[100000], out[100000], ptr;

int sz[(100000 + backet - 1) / backet][10];
int convert[(100000 + backet - 1) / backet][10];
int data[100000];

void tour(int idx, int par = -1)
{
  in[idx] = ptr++;
  for(int &to : g[idx]) if(to != par) tour(to, idx);
  out[idx] = ptr;
}

void push(int k)
{
  for(int i = k * backet; i < min(N, (k + 1) * backet); i++) {
    data[i] = convert[k][data[i]];
  }
  for(int i = 0; i < 10; i++) {
    convert[k][i] = i;
    sz[k][i] = 0;
  }
  for(int i = k * backet; i < min(N, (k + 1) * backet); i++) {
    sz[k][data[i]]++;
  }
}

int main()
{
  cin >> N >> Q;
  for(int i = 1; i < N; i++) {
    int U, V;
    cin >> U >> V;
    g[U].push_back(V);
    g[V].push_back(U);
  }
  tour(0);

  int all = (N + backet - 1) / backet;
  for(int i = 0; i < all; i++) {
    sz[i][0] += min(N, (i + 1) * backet) - i * backet;
    for(int j = 0; j < 10; j++) convert[i][j] = j;
  }

  while(Q--) {
    int t, s, x, y;
    cin >> t >> s >> x >> y;

    int a = in[s], b = out[s];

    if(t == 1) {
      int sum = 0;
      for(int i = 0; i < all; i++) {
        int l = i * backet, r = min(N, (i + 1) * backet);
        if(a >= r || b <= l) continue;
        if(a <= l && r <= b) {
          for(int k = 0; k < 10; k++) {
            if(x <= convert[i][k] && convert[i][k] <= y) sum += sz[i][k];
          }
        } else {
          push(i);
          for(int j = max(a, l); j < min(b, r); j++) {
            if(x <= data[j] && data[j] <= y) sum++;
          }
        }
      }
      cout << sum << endl;
    } else {
      for(int i = 0; i < all; i++) {
        int l = i * backet, r = min(N, (i + 1) * backet);
        if(a >= r || b <= l) continue;
        if(a <= l && r <= b) {
          for(int k = 0; k < 10; k++) {
            if(convert[i][k] == x) convert[i][k] = y;
          }
        } else {
          push(i);
          for(int j = max(a, l); j < min(b, r); j++) {
            if(data[j] == x) {
              data[j] = y;
              --sz[i][x];
              ++sz[i][y];
            }
          }
        }
      }
    }
  }
}