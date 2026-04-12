#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007
int u[111100];
vector<int>i;
vector<int>y;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,d=1,e;
  cin >>a;
  for(int n=0;n<a;n++){
    cin >>u[n];
  }
  b=u[0];
  for(int n=1;n<a;n++){
    if(b<=u[n]) d++,b=u[n];
  }
  cout <<d<<'\n';
  return (0);
}
