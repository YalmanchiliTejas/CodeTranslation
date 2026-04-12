#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  long long int sum=0;
  vector<long long int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  while(1){
    sort(a.begin(),a.end());
    if(a[n-1]==(n-1))break;
    long long int wl=a[n-1]/n;
    sum+=wl;
    for(int i=0;i<n-1;i++){
      a[i]+=wl;
    }
    a[n-1]-=wl*n;
  }

  cout<<sum<<endl;

  return 0;
}
