#include <iostream>
#include <vector>
using namespace std;

const unsigned int M = 1000000007;
int  N;

int main(){
    cin >> N;
    vector<long long> A;
    for(int i = 0; i < N; i++){
        long long x; 
        cin >> x;
        A.push_back(x);
    }

    long long sum = 0; 
    long long suffix = A[N-1];
    for(int i = N-2; i > -1; i--){
        sum += (A[i] * suffix);
        sum %= M;
        suffix += A[i];
        suffix %= M;
    }


    cout << sum << endl;
}
