#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
cin>>N;
char S[N];
for(int i=0;i<N;i++){
cin>>S[i];
}
cin>>K;
char a;
a = S[K-1];
for(int i = 0;i<N;i++){
  if(S[i]!=a){
    S[i]='*';
  }
}
for(int i=0;i<N;i++){
  cout<<S[i];
}
}