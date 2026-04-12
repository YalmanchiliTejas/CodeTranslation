#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i,n) for(ll i =0;i<n;++i)

int main(){
  int n,q;
  cin>>n>>q;
  int pos=1;
  REP(i,q){
      int t;cin>>t;
      int k;cin>>k;
     
      if(t==0){
           int tar;
            if(pos+k-1>n)tar=pos+k-1-n;
            else tar=pos+k-1;
            cout<<tar<<endl;
      }else{
          k++;
        int tar;
        if(pos+k-1>n)tar=pos+k-1-n;
        else tar=pos+k-1;
        pos=tar;
      }
  }
}

