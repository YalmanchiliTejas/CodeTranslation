#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,t,e;
int x[101];
int main(){
  cin >> n >> t >> e;
  for(int i=0;i<n;i++){
    scanf("%d",&x[i]);
  }

  for(int i=0;i<n;i++){
    int m = t%x[i];
    if(m <= e || x[i] - m <= e ){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}