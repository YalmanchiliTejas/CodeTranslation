#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n,n!=0){
    vector<int> point(n);
    for(int i=0;i<n;i++)
      cin>>point[i];
    sort(point.begin(),point.end());
    int ave=0;    
    for(int i=1;i<n-1;i++)
      ave+=point[i];
    ave/=(n-2);
    cout<<ave<<endl;
  }
  return 0;
}