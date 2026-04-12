#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<unistd.h>
#include <array>
#include <map> 
#define ALL(a)  (a).begin(),(a).end()



using namespace std;
typedef long long ll;
struct point{
  int x;
  int y;

};
int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b % a, a);
}
int lcm( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm
int input(){
  int x;
  cin>>x;
  return x;
}

int moji(char in)
{
    int ans = (int)in-(int)'a';
    if((ans < 0) || (ans > 25)){
        ans = 26;
    }
    return ans;
}
const int VV=10;//場合に応じてVVの値のみ変更する必要あり
//dijkstra(s)sがスタート地点でそこからの最短距離を配列dで表す。正の重みのみ使用可能
int cost[VV][VV];
int d[VV];
bool used[VV];
void dijkstra(int s){
  fill(d,d+VV,100000);
  fill(used,used+VV,false);
  d[s]=0;
  while(true){
    int v=-1;
    for(int u=0;u<VV;u++){
      if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
    }
    if(v==-1)break;
    used[v]=true;
    for(int u=0;u<VV;u++){
      d[u]=min(d[u],d[v]+cost[v][u]);
    }
  }

}

int compare_int(const void *a, const void *b)//qsort(quick sort利用時に使用)
{
    return *(int*)a - *(int*)b;
}

int binary_searchh(long long x,long long k[],int n){
  int l=0;
  int r=n;
  while(r-l>=1){
    int i=(l+r)/2;
    if(k[i]==x)return i;
    else if(k[i]<x)l=i+1;
    else r=i;
  }
  return -1;
}

struct File {
    int aa;
    int bb;

    File(const int& aa, const int& bb)
        : aa(aa), bb(bb) {}
};

bool operator<(const File& a, const File& b)
{
    // ファイル種別、ファイル名の順番で優先順位を付けて比較
    return std::tie(a.aa, a.bb) < std::tie(b.aa, b.bb);
}

long long kaijo(long long x){
  long long l=10*10*10*10*10*10*10*10*10+7;
  long long sum=1;
  for(int i=x;i>0;i--){
    sum*=i;
    if(sum>l){
      sum%=l;
    }
  }
  return sum;
}






int main(){
  int H,W;
  cin>>H>>W;
  char A[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A[i][j];
    }
  }
  int i=0;
  int j=0;
  while(true){
    bool ok=false;
    bool okk=false;
    if(i+1<H){
      if(A[i+1][j]=='#'){
        A[i][j]='.';
        i++;
        ok=true;
      }
    }
    if(!ok){
      if(j+1<W){
        if(A[i][j+1]=='#'){
          A[i][j]='.';
          j++;
          okk=true;

        }
      }
    }
    if(!ok&&!okk){
      A[i][j]='.';
      break;
    }

  }
  bool hantei=false;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]=='#'){
        hantei=true;
        break;
      }
    }
  }
  if(hantei){
    cout<<"Impossible"<<endl;
  }else{
    cout<<"Possible"<<endl;
  }


}


