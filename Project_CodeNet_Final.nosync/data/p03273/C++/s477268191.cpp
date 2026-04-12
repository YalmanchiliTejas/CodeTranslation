#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;

int h,w,x;
char s[1000][1000];
bool visited [1000][1000];
pair<int,int> start,goal;
queue<pair<int,pair<int,int>>> q;
vector<pair<int,int>> ino;

int main(){
  int h,w;cin>>h>>w;
  string map[100];
  rep(i,h){
    cin>>map[i];
  }
  rep(i,w){
    bool e = true;
    rep(j,h){
      if(map[j][i]=='#'){
        e=false;
        break;
      }
    }
    if(e){
      rep(j,h){
        map[j].erase(i,1);
      }
      w--;i--;
    }
  }
  rep(i,h){
    bool e = false;
    rep(j,w){
      if(map[i][j]=='#')e = true;
    }
    if(e)cout << map[i]<<endl;
  }
}
