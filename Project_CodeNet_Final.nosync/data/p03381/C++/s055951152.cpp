#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
const int MOD=1000000007;

int main(){
    int N;
    lint A[200000],B[200000];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        B[i]=A[i];
    }
    sort(A,A+N);
    for(int i=0;i<N;i++){
        if(B[i]<A[N/2]) cout << A[N/2] << endl;
        else cout << A[N/2-1] << endl;
    }

    return 0;
}