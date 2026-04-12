#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 10000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;

int C[10][10],perm[10]={1,2,3,4,5,6,7,8};
bool flag=true;

int main(){
  int N,M,a,b,ans=0,count=0;
  cin>>N>>M;

  for(int i=0;i<M;i++){
    cin>>a>>b;
    C[a][b]++; C[b][a]++;
  }
  
  do{
    //for(int i=0;i<N;i++) cout<<perm[i]<<endl;
    //count++;
    for(int i=1;i<N;i++){
      if(C[perm[i-1]][perm[i]]==0) flag=false;
    }
    if(flag) ans++;
    flag=true;
  }while(next_permutation(perm+1,perm+N));
  //cout<<count<<endl;
  cout<<ans<<endl;
}
