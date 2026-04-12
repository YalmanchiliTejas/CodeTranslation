#include <iostream>
using namespace std;
int main(){
string S;
int N,K;
string result;
cin>>N>>S>>K;
char replace = S[K-1];
for(int i=0; i<N; i++){
if((char)S[i]!=replace) result+="*";
else result+=S[i];
}
cout<<result;
  return 0;
}