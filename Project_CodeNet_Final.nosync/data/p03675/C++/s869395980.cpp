#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int n;cin>>n;
  vector<int> vec(n);
  for(auto &e: vec)cin>>e;
  if(n&1){
    for(int i=n-1;i>=0;i-=2){
      cout<<vec[i];
      if(n==1)cout<<endl;
      else cout<<" ";
    }
    for(int i=1;i<n-1;i+=2){
      cout<<vec[i];
      if(i!=n-2)cout<<" ";
      else cout<<endl;
    }
  }else{
    for(int i=n-1;i>=1;i-=2){
      cout<<vec[i]<<" ";
    }
    for(int i=0;i<n-1;i+=2){
      cout<<vec[i];
      if(i!=n-2)cout<<" ";
      else cout<<endl;
    }
  }
}
