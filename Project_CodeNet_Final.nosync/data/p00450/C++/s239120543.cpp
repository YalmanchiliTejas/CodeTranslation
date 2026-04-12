#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define F first
#define S second
typedef pair<int,int> P;
int N;
P A[100002];
int main(){
  while(1){
    scanf("%d",&N);
    if(!N) break;
    int id=0;
    int a;
    scanf("%d",&a);
    A[id].F = 1;
    A[id].S = a;
    for(int i=2;i<=N;i++){
      scanf("%d",&a);
      if(a == (A[id].S)){
	A[id].F++;
      } else {
	if(i%2==0){
	  for(int k=id;k>-1;k--){
	    if(A[k].S==a) break;
	    A[k].S=a;
	  }
	  A[id].F++;
	} else {
	  id++;
	  A[id].F=0;
	  A[id].S=a;
	  A[id].F++;
	}
      }
      //  printf("%d %d %d\n",id,A[id].F,A[id].S);
    }
    int res=0;
    for(int i=0;i<=id;i++){
      //      printf("%d %d\n",A[i].F,A[i].S);
      if(A[i].S==0) res+=A[i].F;
    }
    printf("%d\n",res);
  }
}