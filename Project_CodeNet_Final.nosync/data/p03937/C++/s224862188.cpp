#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd(b,a%b);
  }
}
 
long long lcm(long long x, long long y){
  return (x/gcd(x,y))*y;
}
 
class UnionFind {
    public:
    //各頂点の親の番号を格納する。その頂点自身が親だった場合は-(その集合のサイズ)を入れる。
    vector<int> Parent;
    
    //クラスを作るときは、Parentの値を全て-1にする。
    //以下のようにすると全てバラバラの頂点として解釈できる。
    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    
    //自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];//先祖をrootで取っておきたい。
    }
    
    //AとBをくっ付ける
    bool connect(int A, int B) {
        //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }
        
        //大きい方(A)に小さいほう(B)をくっ付けたい
        //大小が逆だったらAとBをひっくり返す。
        if (size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        //Bの親をAに変更する
        Parent[B] = A;
        
        return true;
    }
};

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  REP(i,h){
    cin>>a[i];
  }
  int x=0,y=0;
  int dx[]={1,0,-1,0};
  int dy[]={0,1,0,-1};
  bool down=false,right=false;
  bool flag=true;
  int nx,ny;
  set<pair<int,int> > path;
  path.insert(make_pair(0,0));
  while(x != h-1 || y != w-1){
    down = false;right=false;
    REP(i,4){
      nx = x+dx[i];
      ny = y+dy[i];
      if(0<=nx && nx<h && 0<=ny && ny<w){
        if(a[nx][ny]=='.'){
          continue;
        }else{
          if(i>=2){
            if(path.find(make_pair(nx,ny))!=path.end()){
              continue;
            }else{
              flag = false;
              break;
            }
          }else{
            if(i==0){
              down = true;
            }else{
              right = true;
            }
          }
        }
      }
    }
    if(!flag){
      break;
    }
    if((down && right) || (!down && !right)){
      flag = false;
      break;
    }else if(down){
      path.insert(make_pair(x+1,y));
      x = x+1;
    }else{
      path.insert(make_pair(x,y+1));
      y = y+1;
    }
  }
  if(flag){
    if(a[h-1][w-2]=='#' && a[h-2][w-1]=='#'){
      cout<<"Impossible"<<endl;
    }else{
      cout<<"Possible"<<endl;
    }
  }else{
    cout<<"Impossible"<<endl;
  }
  return 0;
}
