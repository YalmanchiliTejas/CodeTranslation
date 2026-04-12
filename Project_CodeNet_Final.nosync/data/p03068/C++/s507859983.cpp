#include <iostream>
#include <string>
using namespace std;

int main(){
int N,K;
cin>>N;
string S(N,'-');
cin>>S>>K;
K=S[K-1];
for(int i=0;i<N;i++){
if(S[i] != K){
S[i] = '*';
}
}

cout<<S;

return 0;
}
