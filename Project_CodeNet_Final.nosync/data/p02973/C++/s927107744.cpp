#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;
vector<int>vec;

int bs(int a){
  int l=-1,r=(int)vec.size();
  while(r-l>1){
    int mid=(l+r)/2;
    if(vec[mid]<a){
      r=mid;
    }
    else{
      l=mid;
    }
  }
  return r;
}

int main(){
  int n;
  int a[100009];
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }
  vec.push_back(a[0]);
  for(int i=1;i<n;i++){
    int idx=bs(a[i]);
    if(idx==vec.size()){
      vec.push_back(a[i]);
    }
    else{
      vec[idx]=a[i];
    }
  }
  cout<<vec.size()<<endl;
  return(0);
}
