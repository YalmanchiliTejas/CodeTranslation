#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<char> S(N);
   for(int i=0;i<N;i++){
      cin>>S[i];
   }
   int K;
   cin>>K;
   char temp=S[K-1];
   for(int i=0;i<N;i++){
      if(S[i]!=temp){
         S[i]='*';
      }
   }
   for(int i=0;i<N;i++){
      cout<<S[i];
   }
   cout<<endl;
   return 0;
}
