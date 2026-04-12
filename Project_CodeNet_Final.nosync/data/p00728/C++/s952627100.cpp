//ICPC Score Totalizer Software
#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  int n;
  while(true){
    cin>>n;
    if(n==0)break;
    int sum=0;
    vector<int> v;
    rep(i,n){
      int tmp;
      cin>>tmp;
      sum+=tmp;
      v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cout<<(sum-v[0]-v[n-1])/(n-2)<<endl;
  }
  return 0;
}