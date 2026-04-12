#include <iostream>
using namespace std;


int main() {
    int n;
    while (cin >> n && n>0) {
       int sum,L,M,s;
       L = 0;
       M = 1000;
       sum = 0;
       for (int i=0;i<n;i++) {
            cin >> s;
            if (s>L) L=s;
            if (s<M) M=s;
            sum += s; 
       }
       sum -= L+M;
       sum /= n-2;
       cout << sum << endl;  
       }
}

