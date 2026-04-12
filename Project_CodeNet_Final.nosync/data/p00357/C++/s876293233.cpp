#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  int n;
  cin>>n;
  int mx=0;
  vector<int> v;
  bool f=true;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
    if(mx<i) f=false;
    mx=max(a/10+i,mx);
  }
  int mn=0;
  for(int i=n-1;i>=0;i--){
    int pos=(n-1)-i;
    if(mn<pos) f=false;
    mn=max(v[i]/10+pos,mn);
  }
  cout<<(f?"yes":"no")<<endl;
}

