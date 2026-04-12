#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
  int n;cin>>n;
  int h[20];
  for(int i=0;i<n;++i)
	cin>>h[i];

  int mx=0;
  int ans=0;
  for(int i=0;i<n;++i){
	if(mx<=h[i])ans++;
	mx=max(mx,h[i]);
  }
  cout<<ans<<endl;
  return 0;
}