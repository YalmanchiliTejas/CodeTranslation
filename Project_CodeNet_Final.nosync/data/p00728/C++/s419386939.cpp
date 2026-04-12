#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int INF = 1e9;


int main(){
  int n;
  while(1){
    cin>>n;
    if(n==0){
      break;
    }
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.erase(a.end()-1);
    a.erase(a.begin());
    int sum=0;
    for(int i=0;i<a.size();i++){
      sum+=a[i];
    }
    cout<<sum/a.size()<<endl;
  }
  return 0;
}

