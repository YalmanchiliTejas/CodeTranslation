#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans=0;
  int maxx=-1;
  for(int i=0;i<n;i++){
    maxx=max(maxx,a[i]);
    if(maxx==a[i])ans++;
  }
  cout<<ans<<endl;
}

  