#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int main(){
  int i,j,k,n,x,max=0,cnt=0;
  cin >>n;
  for(i=0;i<n;i++){
    cin >> x;
    if(x>=max){
      max=x;
      cnt++;
    }
  }
  cout << cnt <<endl;
  return 0;
}