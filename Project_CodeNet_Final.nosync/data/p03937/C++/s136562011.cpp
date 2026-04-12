#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define SUM(n) ((n)+1)*(n)/2　//1〜nまでの総和を求める式
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1) //小数点桁数を指定する
#define abs(x,y) (max(x,y)-min(x,y))
#define all(v) v.begin(),v.end()
#define UPDight(a,b) (a+b-1)/b //小数点切り上げ 
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD=int(1e9)+7; 
using namespace std;
using pii = pair<int,int>;
typedef vector<int> vit;

int h, w;
string mas[10];
bool isvisited[10][10] = {false};

void dfs(int x, int y){
  if(isvisited[y][x]){
    return;
  }
  if(mas[y][x] != '#'){
    return;
  }
  isvisited[y][x] = true;
  dfs(x + 1, y);
  if(mas[y][x + 1] != '#'){
      dfs(x, y + 1);
  }
  return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    rep(i, h){
      cin >> mas[i];
    }
    dfs(0, 0);
    rep(i, h){
      rep(j, w){
	if(!isvisited[i][j] && mas[i][j] == '#'){
	  cout << "Impossible\n";
	  return 0;
	}
      }
    }
    cout << "Possible\n";
    return 0;
}
