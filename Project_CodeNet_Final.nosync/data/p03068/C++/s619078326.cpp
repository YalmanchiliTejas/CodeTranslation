#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K,i;
     string S;
     cin >> N>>S>>K;
     for (int i = 0; i < N; ++i){

       if(S[i] != S[K-1]){
          S[i] = '*';
       }
     }

     cout << S;
}

