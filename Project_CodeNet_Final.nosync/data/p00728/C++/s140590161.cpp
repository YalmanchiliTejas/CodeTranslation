#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(){
  while(1){
  int n;
  cin >> n;
  if(n==0) break;
  vector<int> a;
  int tmp=0;
  for(int i=0;i<n;i++) {
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(),a.end());
  int ave=0;
  for(int i=1;i<n-1;i++){
    ave+=a[i];
  }
  ave=ave/(n-2);

  cout << ave << endl;
  }
  return 0;

}