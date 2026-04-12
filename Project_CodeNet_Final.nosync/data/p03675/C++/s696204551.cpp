#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <vector>

typedef long long ll;
#define fi first
#define se second

const ll mod = 1000000007;
//              123456789

using namespace std;

////////////////////////////////
//
//
////////////////////////////////

///////////////////////////////
//////////////////////////////


int a[212345];
int N;

int main(){
  
  cin>>N;
  int i;
  
  for( i = 0; i < N; i++ ){
  	scanf("%d", a+i);
  }
  
  for( i = N-1; i >= 0; i -= 2 ){
  	if( i != N-1 ) printf(" ");
  	printf("%d", a[i]);
  	
  }
  
  for( i = N%2; i < N; i += 2){
  	printf(" %d", a[i]);
  }

  
  return 0;
}