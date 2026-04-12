#include <bits/stdc++.h>
using namespace std;
long long all(int level) {
    if(level==0) return 1;
    return 2 * all(level-1) + 3;
}

long long pate(int level, long long X) {
    if(level==0) return 1;
    
    long long l = all(level-1);
    
    if(X==1) return 0;
    if(X<=l+1) return pate(level-1, X-1);
    if(X==l+2) return pate(level-1, l) + 1;
    if(X<=2*l+2) return pate(level-1, l) + 1 + pate(level-1, X-l-2);
    return 2*pate(level-1, l) + 1;
    
}

int main() {
    int N; long long X;
    cin >> N >> X;
    cout << pate(N, X) << endl;
}
