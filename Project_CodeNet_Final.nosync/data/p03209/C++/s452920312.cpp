#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    long long int N,K,i;
    cin >> N >> K;
  
    long long int A[N + 1];
    long long int P[N + 1];
    A[0] = 1;
    P[0] = 1;
    for(i = 1;i <= N;i++){
        A[i] = 2 * A[i - 1] + 3;
        P[i] = 2 * P[i - 1] + 1;
    }
    long long int count = 0;
    for(i = N; i > 0; i--){
        if(K == 0) break;
        K--;
        if(K <= A[i - 1]) continue;
        K -=A[i - 1] + 1;
        count += P[i - 1] + 1;
    }
    if(K) count++;
    cout << count << "\n";
    return 0;
}