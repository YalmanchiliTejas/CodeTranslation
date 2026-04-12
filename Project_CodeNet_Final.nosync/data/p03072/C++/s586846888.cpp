#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,i;cin>>n;
  	int sum,ans=1;
	vector<int>v(n);
  	for(i=0;i<n;++i)cin>>v[i];
  	for(i=n-1;i>=1;--i){
      sum=0;
      for(int j=i;j>=0;--j)if(v[i]>=v[i-j])++sum;
      if(sum==i+1)++ans;
    }
  cout<<ans<<endl;return 0;
}
