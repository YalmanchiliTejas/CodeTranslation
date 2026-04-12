#include<iostream>
#include<cmath>
using namespace std;

long pathi(long N, long X) {
    if(N==0){
        if(X==1){
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (X==1){
            return 0;
        }
        else if(X<=pow(2, N+1)-2){
            return pathi(N-1, X-1);
        }
        else if(X == pow(2, N+1)-1) {
            return pathi(N-1, pow(2, N+1)-3) + 1;
        }
        else if(X<=pow(2, N+2)-4){
            return pathi(N-1, pow(2, N+1)-3) + 1 + pathi(N-1, X-pow(2, N+1)+1);
        }
        else {
            return 2*pathi(N-1, pow(2, N+1)-3) + 1;
        }
    }
}

int main() {
    long N, X;
    cin>>N>>X;
    long ans = pathi(N, X);
    cout<<ans<<endl;
}
