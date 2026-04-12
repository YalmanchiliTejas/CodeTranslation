#include <iostream>
#include <string>
#include <stdlib.h>

#define INC(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define DEC(i, a, b) for(int (i) = (a); (i) > (b); --(i))
#define REP(i, n)    INC(i, 0, n)
#define comp(a, b) int comp(const void *(a), const void *(b))

typedef unsigned int uint;
typedef unsigned long ul;
typedef long long  ll;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;

using namespace std;

void TFprint(bool b, std::string T, std::string F){
    if(b){
        cout << T << endl;
    }else{
        cout << F << endl;
    }
}

int abs(int x){
    return x > 0? x : -x;
}

int max(int a, int b){
    return a > b? a : b;
}

int min(int a, int b){
    return a < b? a : b;
}


int main(){
    int Acost, Bcost, ABcost;
    int needA, needB;
    cin >> Acost >> Bcost >> ABcost >> needA >> needB;
    int ans = 0;
    int AandAB, BandAB, AandB;

    AandAB = 2 * ABcost * needB + max(0, needA - needB) * Acost;
    BandAB = 2 * ABcost * needA + max(0, needB - needA) * Bcost;
    AandB = Acost * needA + Bcost * needB;
    cout << min(AandAB, min(BandAB, AandB)) << endl;
    return 0;
}
