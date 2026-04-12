#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a,b,c;
  string S;
  char s;
  cin>>N>>S>>a;
  s =S.at(a-1);
  for(int i=0;i<N;i++){
    if (S.at(i)!=s){
      S.at(i)= '*' ;
    }
  }
  cout<<S<<endl;
}
