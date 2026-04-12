#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int N;
   char S[11];
   int K;
   cin >> N >> S >> K;
   for(int i = 0; i < N; i++){
       if(S[i]!=S[K - 1]){
           S[i] = '*';
       }

   }
   cout << S;
   return 0;
}