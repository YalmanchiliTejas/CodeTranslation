#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
int h,w;
string a[8];

int dfs(int x, int y){
  int dep=-1000;
  int dep2=-1000;
  bool update=false;
  //  cout << a[0][1] << a[1][0] << endl;
  //  cout << x+1 << " " << w-1 << endl;
  if(x+1<=w-1){
    //    cout << " " << endl;
    if(a[y][x+1]=='#'){
      dep=dfs(x+1,y)+1;
      update=true;
      //      cout << a[0][1] << endl;
    }                                                                    
  }                                                                     
  if(y+1<=h-1){                                                          
    if(a[y+1][x]=='#'){                                                  
      dep2=dfs(x,y+1)+1;
      update=true;
    }                                                                    
  }
  if(x==w-1 && y==h-1){
    dep=0;
    update=true;
  }
  //  cout << x << " " << y << " " << max(dep,dep2) << endl;
  if(update) return max(dep,dep2);
  else return -100000;
}




int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  rep(i,h){
    cin >> a[i];
  }
  int c=0;
  rep(i,h) rep(j,w) {
    if(a[i][j]=='#') c++;
  }
  int reach=dfs(0,0)+1;
  if(reach==c){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  //  cout << reach << endl;
  /*rep(i,h) rep(j,w){
    cout << a[i][j];
    } */   
  /*  queue<pair<int, int> > q;
  q.push(mp(0,0));
  bool reach=false;
  while(!q.empty()){
    pair<int, int> t;
    t=q.front();q.pop();
    int x=t.first;
    int y=t.second;
    if(x==w-1 && y==h-1){
      reach=true;
      break;
    }
    if(x+1<=w-1){
      if(a[y][x+1]=='#'){
	q.push(mp(x+1,y));
      }
    }
    if(y+1<=h-1){
      if(a[y+1][x]=='#'){
	q.push(mp(x,y+1));
      }
    }
    }*/
  //  if(reach) cout << "Possible" << endl;
  //  else cout << "Impossible" << endl;
    
  
  return 0;
    

}
