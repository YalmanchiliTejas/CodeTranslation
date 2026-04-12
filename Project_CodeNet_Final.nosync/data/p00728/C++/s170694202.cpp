#include<iostream>
using namespace std;

int main(){
  int n;
  int sum,maxv,minv,tmp;

  while(cin >> n){
    if(n==0)break;
    
    cin >> sum;
    maxv = minv = sum;
    for(int i=0;i<n-1;i++){
      cin >> tmp;
      sum += tmp;
      if(maxv < tmp)maxv = tmp;
      if(minv > tmp)minv = tmp;
    }

    cout << (sum-maxv-minv)/(n-2) << endl;
  }
}