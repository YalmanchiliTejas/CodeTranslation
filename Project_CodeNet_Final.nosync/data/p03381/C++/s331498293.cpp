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
typedef long long int lli;


int main(void){
  int n;
  cin>>n;
  vector<int >x,y;
  int t;
  for(int i=0;i<n;i++){
    cin>>t;
    x.pb(t);
    y.pb(t);
  }
  sort(x.begin(),x.end());

  for(int i=0;i<n;i++){
    if(y[i]<=x[(n/2)-1]) cout<<x[n/2]<<endl;
    else cout<<x[(n/2)-1]<<endl;
  }

  return 0;
}