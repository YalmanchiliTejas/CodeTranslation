#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  
  while(1){
    vector<int> num(20005,0);
    cin>>n>>m;
    if(n+m==0)break;
  
    for(int i=0;i<n;i++) cin>>num[i];
    for(int j=n;j<n+m;j++) cin>>num[j];

    stable_sort(num.begin(),num.end());

    int ans=0;
    for(int i=0;i<num.size()-1;i++){
      ans=max(ans,num[i+1]-num[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}