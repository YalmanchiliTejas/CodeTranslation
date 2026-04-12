//05
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  for(int n;cin>>n,n;){
    double h=-1,l=1<<30,sum=0;
    for(int i=0;i<n;i++){
      double s;
      cin>>s;
      sum+=s;
      h=max(s,h);
      l=min(s,l);
    }
    cout<<int((sum-h-l)/(n-2))<<endl;
  }
  return 0;
}