#include <bits/stdc++.h>
using namespace std;

int main() {
   long long N,X,M;
   cin >> N >> X >> M;
   set<int> S;
   vector<long long> A;
   int size=0,cycle;
   A.push_back(X);
   size++;
   while (!S.count(A[size-1])) {
       S.insert(A[size-1]);
       long long B=(A[size-1]*A[size-1])%M;
       //cout << B << endl;
       A.push_back(B);
       size++;
   }
   vector<long long> B;
   long long count=0;
   for (int i=0; i<size; i++) {
       if (A[i]==A[size-1]) {
           cycle=size-1-i;
           for (int j=i+1; j<size; j++) {
               B.push_back(A[j]);
           }
           break;
       }
   }
   long long C=0;
   for (int i=0; i<cycle; i++) C+=B[i];
   for (int i=0; i<size; i++) {
       count+=A[i];
       //cout << A[i] << endl;
       N--;
       if (N==0) break;
   }
   count+=(N/cycle)*C;
   for (int i=0; i<N%cycle; i++) count+=B[i];
   cout << count << endl;
}