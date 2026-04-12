#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n,a;
  cin>>n;
  vector<int> b;
  for(int i=0;i<n;i++){
    cin>>a;
    if(i==0) b.push_back(a);
    else{
      if(b[b.size()-1]<a)b[b.size()-1]=a;
      else if(b[0]>=a){
        b.insert(b.begin(),a);
      }else{
        b[lower_bound(b.begin(),b.end(),a)-b.begin()-1]=a;
      }
    }
  }
  cout<<b.size();
}