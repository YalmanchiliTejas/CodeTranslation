#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

/*
   cin.tie(0);
   ios::sync_with_stdio(false);
   */

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

char board[10][10];
int x=0,y=0;

void print_board(){
  rep(i,y){
    rep(j,x)cout<<board[i][j];
    cout<<endl;
  }
}

void to_board(string s){
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='/'){
      x=0;y++;
    }else if(isdigit(s[i])){
      rep(j,s[i]-'0'){board[y][x]='.';x++;}
    }else{
      board[y][x]='b';x++;
    }
  }
  y++;
}

string to_jfen(){
  string ret="";
  for(int i=0;i<y;i++){
    int cnt=0;
    for(int j=0;j<x;j++){
      if(board[i][j]=='b'){
	if(cnt!=0)ret+=to_string(cnt);
	ret.push_back('b');
	cnt=0;
      }else{
	cnt++;
      }
    }
    if(cnt!=0)ret+=to_string(cnt);
    if(i!=y-1)ret+='/';
  }
  return ret;
}

void solve(string s){
  x=0;y=0;
  to_board(s);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  a--;b--;c--;d--;
  swap(board[a][b],board[c][d]);
  cout<<to_jfen()<<endl;
}

int main(){
  string s;
  while(cin>>s){
    if(s=="#")break;
    solve(s);
  }
  return 0;
}

