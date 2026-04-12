#include <bits/stdc++.h>
using namespace std;

int main() {
   int N,M;
   cin >> N >> M;
   int A[M],B[M],P[N];
   for (int i=0; i<M; i++) {
       cin >> A[i] >> B[i];
   }
   for (int i=0; i<N; i++) {
       P[i]=i+1;
   }
   int count=0;
   do {
       if (P[0]!=1) break;
       bool s=true;
       for (int i=0; i<N; i++) {
           bool t=false;
           if (i!=0) {
               for (int j=0; j<M; j++) {
                   if (P[i]==A[j] && P[i-1]==B[j]) t=true;
                   if (P[i]==B[j] && P[i-1]==A[j]) t=true;
               }
               if (!t) s=false;
           }
       }
       if (s) count++;
   }while (next_permutation(P,P+N));
   cout << count << endl;
}