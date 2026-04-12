#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<unsigned long long> A(N);

    for(int i{0}; i<N; ++i){
        cin >> A[i];
    }

    unsigned long long sum{0};

    unsigned long long sum_j{0};
    for(int j{1}; j<N; ++j){
        sum_j += A[j];
    }

    for(int i{0}; i<N-1; ++i){
        sum += A[i] * (sum_j % 1000000007);
        sum = sum % 1000000007 ;
        sum_j -= A[i+1];
    }

    cout << sum << endl;
}
