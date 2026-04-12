#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define llong long long
#define pb(a) push_back(a)
#define strVecSORT(strVec) sort(strVec.begin(), strVec.end());
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

int main(){
  int r,g,b;
  cin>>r>>g>>b;
  int RGB=r*100+g*10+b;
  int ans =RGB%4;
  if(ans==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
