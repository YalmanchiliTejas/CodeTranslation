#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(){
  int n;
  while(1){
    cin >> n;
    if(n==0)break;
    vector<int> p(n);
    int sum=0;
    rep(i,n){
      cin >> p[i];
      sum += p[i];
    }
    int min,max;
    min=*min_element(p.begin(),p.end());
    max=*max_element(p.begin(),p.end());
    sum -= (max+min);
    int avg = sum / (n-2);
    cout << avg << endl;
  }
  return 0;
}

