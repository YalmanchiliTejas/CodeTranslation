#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>




using namespace std;
typedef long long ll;
struct point{
  int x;
  int y;

};
int gcd( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	// ユークリッドの方法
	while( m != n )
	{
		if ( m > n ) m = m - n;
		else         n = n - m;
	}
	return m;
}//gcd
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





int main(){
  int N;
  cin>>N;
  if(N==3||N==5||N==7){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }


  

  



}


  
  

  
