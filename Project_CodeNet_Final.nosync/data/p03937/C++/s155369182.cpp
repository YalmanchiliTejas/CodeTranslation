#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vvchar vector<vector<char>>
#define vdouble vector<double>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;

int h,w;
vstring s(9);
vint dx = {1,0};
vint dy = {0,1};

bool check(int x,int y){
  int count = 0;
  if(x == h-1 && y == w-1) return true;
  rep(i,2){
    //cout << x + dx[i] << " " << y + dy[i] << " " << s[x + dx[i]][y + dy[i]] <<  endl;
    if(x + dx[i] < h && y + dy[i] < w){
      //cout << x + dx[i] << " " << y + dy[i] << " " << s[x + dx[i]][y + dy[i]] <<  endl;
      if(s[x + dx[i]][y + dy[i]] == '#') count++;
    }
  }
  //cout << x << " " << y << " " << count << endl;
  if(count == 1){
    if(s[x + dx[0]][y + dy[0]] == '#'){
      if(y + dy[0] > 0){
        if(s[x + dx[0]][y + dy[0]-1] == '#') return false;
        else return check(x+dx[0],y+dy[0]);
      }
      else return check(x+dx[0],y+dy[0]);
    }
    if(s[x + dx[1]][y + dy[1]] == '#'){
      if(x + dx[1] > 0){
        if(s[x + dx[1]-1][y + dy[1]] == '#') return false;
        else return check(x+dx[1],y+dy[1]);
      }
      else return check(x+dx[1],y+dy[1]);
    }
  }
  //cout << "a" << endl;
  return false;
}

signed main(){
  cin >> h >> w;
  rep(i,h){
    cin >> s[i];
  }
  if(check(0,0)) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}