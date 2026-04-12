#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n,c=0;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    bool f=true;
    for(int j=0;j<i;j++){
      if(a[i]<a[j]) f=false;
    }
    if(f) c++;
  }
  cout<<c;
}
