#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n, m;
bool graph[9][9];
int res = 0;


int main(){
  rep(i, 9)rep(j, 9)graph[i][j] = false;
  cin >> n >> m;
  rep(i, m){
    int a, b;
    cin >> a >> b; a--; b--;
    graph[a][b] = true;
    graph[b][a] = true;
  }
  vector<int> seq(n);
  rep(i, n)seq[i] = i;
  //rep(i, n){rep(j, n)cout << graph[i][j]; cout << endl;}
  do{
    if(seq[0] != 0) break;
    int cnt = 0;
    while(cnt < n - 1 && graph[seq[cnt]][seq[cnt+1]]){
      cnt++;
    }
    if(cnt == n-1) res++;
    //rep(i, n)cout << seq[i];cout << endl;
  }while(next_permutation(seq.begin(), seq.end()));
  
  //res /= 2;
  cout << res << endl;
  return 0;
}