#include<bits/stdc++.h>
using namespace std;
 int main(){
     int N;
     string S;
     int K;
     cin >> N >> S >> K;

     char T = S[K-1];

     for(int i=0;i<S.size();i++){
         if(S[i] != T) S[i] = '*';
     }

     cout << S << endl;

     return 0;
 }