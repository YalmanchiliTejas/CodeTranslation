#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define ll long long
int main(){
  int N,K;
  cin>>N;
  string S;
  cin>>S;
  cin>>K;
  rep(i,N){
    if(S[i]!=S[K-1]) cout<<"*";
    else cout<<S[i];
  }
  cout<<endl;
}