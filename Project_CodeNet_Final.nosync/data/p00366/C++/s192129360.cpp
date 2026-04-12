#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,sum;
vector<int>a(100001),b;
int main(){
  cin>>n;
  rep(i,n)scanf("%d",&a[i]);
  sort(a.begin(),a.begin()+n);
  for(int i=1;i*i<=a[n-1];i++){
    if(a[n-1]%i == 0){
      b.push_back(i);
      b.push_back(a[n-1]/i);
    }
  }
  sort(b.begin(),b.end());
  rep(i,n) sum += *lower_bound(b.begin(),b.end(),a[i]) - a[i];
  cout<< sum <<endl;
}