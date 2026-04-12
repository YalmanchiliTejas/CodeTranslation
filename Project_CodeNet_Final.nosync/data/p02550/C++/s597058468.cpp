#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;


int main(void){
    long long N, X, M;
    cin >> N >> X >> M;
    
    vector<long long> A(2*M+1);
    A[1]=X;
    for(int i=1; i<2*M; i++){
        A[i+1]=A[i]*A[i]%M;
    }
    
    long long ans=0;
    if(N<=2*M){
        for(int i=1; i<=N; i++){
            ans += A[i];
        }
        cout << ans << endl;
        return 0;
    }
    
    long long cycle=0, sum=0, start=0;
    for(int i=2*M-1; i>=M; i--){
        if(A[i]==A[2*M]){
            cycle = 2*M-i;
            start=i+1;
            for(int j=i; j<2*M; j++){
                sum += A[j];
            }
            break;
        }
    }
    
    for(int i=1; i<=2*M; i++){
            ans += A[i];
    }
    ans += sum * ((N-2*M)/cycle);
    long long d=(N-2*M)%cycle;
    for(int i=start; i<start+d; i++){
        ans += A[i];
    }
    
    cout << ans << endl;
    
    
    return 0;
}
