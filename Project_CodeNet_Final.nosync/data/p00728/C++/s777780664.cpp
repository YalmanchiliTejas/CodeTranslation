#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    vector<int>in(n);
    for(int i=0;i<n;i++)cin>>in[i];
    sort(in.begin(),in.end());
    int sum=0;
    for(int i=1;i<n-1;i++)sum+=in[i];
    cout<<sum/(n-2)<<endl;
  }
}