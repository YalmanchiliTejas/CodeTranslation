#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
ll cnt = 0;
bool flag=0;
int dfs(int y,int x);
int h,w;  
char table[100][100];
int dp[100][100];

int main(){
  cin >> h >> w;
 
  rep(i,h){
     rep(j,w){
        cin >> table[i][j];
      
     }
  }
 
dfs(0,0);



rep(i,h){
   rep(j,w){
      if(table[i][j] == '#'){
         cout << "Impossible" << endl;
         return 0;
      }  
   }
}


cout << "Possible" << endl;
return 0;

}

int dfs(int y,int x){
   table[y][x] = '.';
   int nx,ny;
   nx = x+1;
   ny = y+1;
   if(0<=nx && nx<w && 0<=ny && ny<h && table[ny][x] == '#' && table[y][nx] == '#'){
      return 0;
   }

   if( 0<=ny && ny<h && table[ny][x] == '#' ){
      dfs(ny,x);
   }
   if(0<=nx && nx<w &&  table[y][nx] == '#'){
      
      dfs(y,nx);
   }

   
}