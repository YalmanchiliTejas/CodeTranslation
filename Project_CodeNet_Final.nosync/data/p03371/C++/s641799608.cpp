#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


void solve(long long A, long long B, long long C, long long X, long long Y){
    vector<long long> cands = {A*X+B*Y, 2*C*max(X, Y), 2*C*min(X, Y)+max(B*(Y-X), A*(X-Y))};
    cout << *min_element(cands.begin(), cands.end()) << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(A, B, C, X, Y);
    return 0;
}
