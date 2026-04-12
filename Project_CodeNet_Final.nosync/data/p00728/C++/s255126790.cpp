#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  while(cin >>n,n){
    vector<int> num;
    for(int i=0,a; i<n; i++){
      cin >>a;
      num.push_back(a);
    }
    sort(num.begin(),num.end());
    int sum = 0;
    for(int i=1; i<n-1; i++) sum+=num[i];
    cout <<sum/(n-2)<<endl;
  }
  return 0;
}