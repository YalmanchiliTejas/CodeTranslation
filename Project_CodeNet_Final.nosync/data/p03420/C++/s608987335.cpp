#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

int main(void){
  int n,k;
  cin>>n>>k;

  ll res=0;
  for(int b=1;b<=n;b++){
    res+=(n/b)*(max(0,b-k));
    res+=max(0,(n%b)-k+1);
  }
  if(k==0) res-=n;
  cout<<res<<endl;
  return 0;
}
