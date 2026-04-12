#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
  int n,s[100];

  while(cin >> n,n){
  for(int i=0;i<n;i++)cin >> s[i];
  sort(s,s+n);
  cout << accumulate(s+1,s+n-1,0)/(n-2) << endl;
 }
}