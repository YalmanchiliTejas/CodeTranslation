#include <bits/stdc++.h>
using namespace std;

long long npatty(long long N, long long X){
    if(N==0) return 1;
    long long len  = (1LL<<(N+1))-3;
    long long pnum = (1LL<<(N))-1;
    if(X==1) return 0; // "B"
    else if(X<=len+1){ // "B" + (L-1)
        return npatty(N-1, X-1);
    } 
    else if(X==len+2) { // "B" + (L-1) + "P"
        return pnum + 1;
    }
    else if(X<=2*(len+1)){ // "B" + (L-1) + "P" + (L-1)
        return pnum + 1 + npatty(N-1, X-len-2);
    } else {
        return pnum * 2 + 1;
    }
}

int main(){
    long long N, X; cin >> N >> X;
    cout << npatty(N, X) << endl;
}
