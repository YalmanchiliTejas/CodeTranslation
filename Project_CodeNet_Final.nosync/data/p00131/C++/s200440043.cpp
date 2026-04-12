#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 10;
bool m[MAX][MAX],tmp[MAX][MAX];
bool ans[MAX][MAX];
int num;
int dx[] = {-1,0,0,0,1};
int dy[] = {0,-1,0,1,0};

void input(){
  num = 0;

  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++){
      cin >> m[i][j];
      if(m[i][j]) num++;
    }
}

bool isInside(int y, int x){
  return 0<=y&&y<MAX&&0<=x&&x<MAX;
}

void rev(int y, int x, int& now){
  for(int i = 0; i < 5; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if(isInside(ny,nx)){
      tmp[ny][nx] = !tmp[ny][nx];
      if(tmp[ny][nx]) now++;
      else now--;
    }
  }
}

void print(){
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      if(j) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
}

void solve(){

  for(int i = 0; i < (1<<MAX); i++){
    memset(ans,false,sizeof(ans));
    memcpy(tmp,m,sizeof(m));

    int now = num;

    for(int j = 0; j < MAX; j++){
      if(i&(1<<j)){
	ans[0][j] = true;
	rev(0,j,now);
      }
    }

    for(int j = 1; j < MAX; j++)
      for(int k = 0; k < MAX; k++){
	if(tmp[j-1][k]){
	  ans[j][k] = true;
	  rev(j,k,now);
	}
      }

    if(now == 0){
      print();
      break;
    }
  }
}

int main(){
  int n;
  cin >> n;

  while(n--){
    input();
    solve();
  }
  return 0;
}