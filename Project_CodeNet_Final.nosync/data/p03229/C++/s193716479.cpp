#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> a;

void solve(){
  long sum = 0L;
  if(n%2 == 0){
    int k = n/2;
    for(int i = 0; i < k-1; i++){
      sum += 2 * (a[n-1-i] - a[i]);
    }
    sum += a[k] - a[k-1];
  }else{
    int k = (n-1)/2;
    for(int i = 0; i < k-1; i++){
      sum += 2 * (a[n-1-i] - a[i]);
    }
    long tmp1 = a[k+1] + a[k] - 2*a[k-1];
    long tmp2 = 2*a[k+1] - a[k] - a[k-1];
    sum += (tmp1 > tmp2) ? tmp1 : tmp2;
  }
  cout << sum << endl;
}

int main(int argc,char** argv){
  cin >> n;
  for(int i = 0;i < n;i++){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(),a.end());
  solve();
  return 0;
}

