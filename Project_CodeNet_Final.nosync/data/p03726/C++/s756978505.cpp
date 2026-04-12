#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

using namespace std;

#define MAX_N 100005

int N;

vector<int> Edge[MAX_N];

int inEdge[MAX_N];

bool used[MAX_N];

bool dfs(int pos, int cnt = 0)
{
  used[pos] = true;
  int C = 0;
  for (int i = 0; i < Edge[pos].size(); i++) {
    int next = Edge[pos][i];
    if(used[next]){
      continue;
    }
    C++;
    if(dfs(next, cnt+1)){
      return true;
    }
    break;
  }

  if(C == 0 && cnt%2 == 0){
    return true;
  }
  else if(C == 0 && cnt%2 == 1){
    return false;
  }
  else{
    return false;
  }

}

bool ans = false;

//0 1
pair<int, int> solve(int pos, int pre = -1)
{
  bool check = false;

  int l = 0, r = 0;

  for (int i = 0; i < Edge[pos].size(); i++) {
    int next = Edge[pos][i];
    if(next == pre){
      continue;
    }
    check = true;

    pair<int, int> p = solve(next, pos);

    l += p.first;
    r += p.second;
  }

  if(!check){
    return make_pair(0, 1);
  }

  if(r >= 2 || l >= 2){
    ans = true;
    return make_pair(0, 0);
  }

  int retR = 0, retL = 0;

  if(r > 0){
    retL = 1;
  }
  if(l > 0){
    retR = 1;
  }

  return make_pair(retL, retR);
}

int CC[MAX_N];
void nuli(int pos, int pre = -1, int color = 0)
{
  CC[pos] = color;
  color = (color+1) % 2;

  for (int i = 0; i < Edge[pos].size(); i++) {
    int next = Edge[pos][i];
    if(next == pre){
      continue;
    }
    nuli(next, pos, color);
  }

  return;
}

bool check2()
{
  for (int j = 0; j < N; j++) {
    if(CC[j] != 0){
      continue;
    }

    bool ok = true;
    for (int k = 0; k < Edge[j].size() && ok; k++) {
      int next = Edge[j][k];
      if(CC[next] != 0){
        ok = false;
      }
    }

    if(ok)
      return true;
    }

  return false;
}

int SCheck[MAX_N][2];

bool solve3(int pos, int pre = -1);

//自分を使わない
bool solve2(int pos, int pre = -1)
{
  if(SCheck[pos][0] != -1){
    return SCheck[pos][0];
  }

  bool ret = true;
  for (int i = 0; i < Edge[pos].size(); i++) {
    int next = Edge[pos][i];
    if(next == pre){
      continue;
    }
    ret &= solve3(next, pos);
  }

  return SCheck[pos][0] = ret;
}

//自分は使う
bool solve3(int pos, int pre)
{
  if(SCheck[pos][1] != -1){
    return SCheck[pos][1];
  }

  for (int i = 0; i < Edge[pos].size(); i++) {
    int next = Edge[pos][i];
    if(next == pre){
      continue;
    }

    if(solve2(next, pos)){
      bool ret = true;
      for (int j = 0; j < Edge[pos].size() && ret; j++) {
        int next2 = Edge[pos][j];
        if(next2 == pre || next2 == next){
          continue;
        }
        ret &= solve3(next2, pos);
      }

      if(ret){
        return SCheck[pos][1] = true;
      }
    }
  }

  return SCheck[pos][1] = false;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
    inEdge[a]++; inEdge[b]++;
  }

  if(N%2 == 1){
    cout << "First" << endl;
    return 0;
  }

  memset(SCheck, -1, sizeof(SCheck));

  for (int i = 0; i < N; i++) {
    if(inEdge[i] == 1){
      if(!solve3(i)){
        cout << "First" << endl;
      }
      else{
        cout << "Second" << endl;
      }
      return 0;
    }
  }

  return 0;
}
