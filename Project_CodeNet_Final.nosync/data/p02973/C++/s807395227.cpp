#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  
  int res=0;
  vector<int> c;
  c.pb(2e9);
  rep(i,n){
    if(c[c.size()-1]>=a[i]){
      c.pb(a[i]);
      res++;
    }else{
      int p=0,q=c.size()-1;
      int r;
      while(q-p!=1){
        r=(p+q)/2;
        if(c[r]>=a[i]) p=r;
        else q=r;
      }
      c[q]=a[i];
    }
  }
  cout<<res<<endl;
}