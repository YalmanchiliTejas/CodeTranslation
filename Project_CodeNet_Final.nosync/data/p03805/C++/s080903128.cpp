#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include <bitset>
#include<math.h>
#include<queue>
using namespace std;
#define MAX 300000
#define INF 3000
typedef long long ll;
typedef pair<int,int> P;

int c[10][10],dis[1000][1000];
int N,M,ans;
bool flag=true;;
int perm[10];



int main(){
  int data1,data2;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>data1>>data2;
    c[data1-1][data2-1]++;
    c[data2-1][data1-1]++;
  }
  for(int i=0;i<N;i++){
    perm[i]=i;
  }
  do{
    flag=true;
    for(int i=0;i<N-1;i++){
      if(c[perm[i]][perm[i+1]]==0){
        flag=false;
        break;
      }
    }
    if(flag) ans++;
  }while(next_permutation(perm+1,perm+N));
  cout<<ans<<endl;
  
}
