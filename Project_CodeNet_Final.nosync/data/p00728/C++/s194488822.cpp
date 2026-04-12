#include<iostream>
#include<algorithm>
using namespace std;

int main(){

  int n;
  int d[1000];

  while(cin >> n, n){
  for(int i=0;i<n;i++) cin >> d[i];

  sort(d,d+n);

  int sum = 0;
  for(int i=1;i<n-1;i++) sum += d[i];

  cout << sum/(n-2) << endl;
  }
}