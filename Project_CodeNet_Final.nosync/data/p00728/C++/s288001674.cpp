#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

vector<int> v;


int main(){
  int n;
  while(cin>>n,n!=0){
    v.resize(0);
    for(int i=0;i<n;i++){
      int tmp;
      cin>>tmp;
      v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<v.size()-1;i++){
      ans+=v[i];
    }
    ans/=(n-2);
    cout<<ans<<endl;
  }
}