#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
using vll=vector<ll>;
using vi=vector<int>;
int main(){
  int n,i,m=0,c=0;
  cin>>n;
  vi h(n);
  for(i=0;i<n;i++){
    cin>>h.at(i);
    m=max(m,h.at(i));
    if(h.at(i)==m) c++;
  }
  cout<<c<<endl;
}