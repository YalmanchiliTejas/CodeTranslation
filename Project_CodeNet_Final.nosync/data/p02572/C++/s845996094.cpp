#include <bits/stdc++.h>
using namespace std;

const long long p= 1000000007;

int main(){
    int N;
    cin >> N;
    long long A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    long long sum = 0;
    long long ct = 0;
    for(int i = 0; i < N; i++){
        sum = (sum + A[i])%p;
        ct = (ct +  A[i]*A[i])%p;
    }
    long long pinv = (p+1)/2;
    cout << pinv*((p + sum*sum -ct)%p)%p<< endl;
}