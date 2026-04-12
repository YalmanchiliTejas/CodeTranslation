#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
#define le 1000000007;
int main(){
  while(1==1){
  int n;
  cin >> n;
  if(n==0)break;
  long long int sum=0;
  vector<int> v(n,0);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  for(int i=1;i<n-1;i++){
    sum+=v[i];
  }
  cout << sum/(n-2) << endl;
  }
  return 0;
}