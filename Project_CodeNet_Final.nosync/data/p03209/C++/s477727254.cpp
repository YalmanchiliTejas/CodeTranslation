#include <bits/stdc++.h>
using namespace std;
long long int memo1[51] = {1};
long long int memo2[51] = {1};
long long int tall(int L){
    if(L == 0) return memo1[0];
    else{
        if(memo1[L] != 0) return memo1[L];
        return memo1[L] = 3 + 2*tall(L-1);
    }
}

long long int paty(int L){
    if(L == 0) return memo2[0];
    else{
        if(memo2[L] != 0) return memo2[L];
        return memo2[L] = 1 + 2*paty(L-1);
    }
}

long long int P(int L,long long int x){
    if(x == 1 && L == 0) return 1;
    else if(x == 1) return 0;
    else if(1 < x && x <= 1 + tall(L-1)) return P(L-1,x-1);
    else if(x == 2 + tall(L-1)) return paty(L-1) + 1;
    else if(2 + tall(L-1) < x && x <= 2 + 2*tall(L-1)) return 1 + paty(L-1) + P(L-1,x - 2 - tall(L-1));
    else if(2 + 2*tall(L-1) < x) return paty(L);
}

int main(){
    long long int N,x;
    cin >> N >> x;
    cout << P(N,x) << endl;
    return 0;
}