#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
 long long N,a,b,c,d,ans,ans2,p;
cin>>S;
  N=S.size();
  ans=0;
  for(int i=0;i<N-1;i++){
 if(S[i]=='A'&&S[i+1]=='C'){
   cout<<"Yes"<<endl;
   return 0;
 }
  }
    cout<<"No"<<endl;
}
