#include <bits/stdc++.h>
 
#define INF 100100100
#define MOD 1000000007
 
using namespace std;
using ll = long long;
using ull = unsigned long long ;
 
int main(){
   int N, K;
   string S;
   cin>>N>>S>>K;
   
   for(int i=0; i<N; i++) {
       if(S[K-1]!=S[i]) {
           S[i] = '*';
       }
   }
   
   cout<<S<<endl;

    return 0;
}