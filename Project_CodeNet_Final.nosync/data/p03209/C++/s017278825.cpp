#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL get(int level,LL h){
  if(level==0)return 1;
  LL s=pow(LL(2),level+2)-3;
  if(h==1)return 0;
  if(h==s)return pow(LL(2),level+1)-1;
  if(h<=(s-1)/2)return get(level-1,h-1);
  if(h==(s+1)/2)return get(level-1,(s-1)/2-1)+1;
  return get(level-1,(s-1)/2-1)+1+get(level-1,h-(s+1)/2);
}
int main(){
  int N;LL X;cin>>N>>X;
  cout<<get(N,X)<<endl;
}