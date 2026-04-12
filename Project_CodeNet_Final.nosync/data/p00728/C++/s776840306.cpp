#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int N;
        cin >> N;
        if(N==0) break;
        vector<int> A(N,0);
        for(int i=0;i<N;i++){
            cin >> A[i];
        }
        int M=0;
        int m=1000;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(M<A[i]){M=A[i];}
            if(m>A[i]){m=A[i];}
        }
        cout << (sum-M-m)/(N-2) << endl;
    }
}

