#include<iostream>
using namespace std;

int main(){
    long N,K,b,p,r;
    long long count = 0;
    //N = p*b+r
    cin >> N >> K;
    b=N;
    while(b>K){
        p = N/b;
        r = N-p*b;
        count += p*(b-K)-(int)(K==0);
        if(r>=K){
            count += r-K+1;
        }
        b--;
    }

    cout << count << "\n";

    return 0;
}