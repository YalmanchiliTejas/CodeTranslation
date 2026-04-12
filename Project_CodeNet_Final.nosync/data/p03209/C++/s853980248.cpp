#include <algorithm>
#include <iostream>
using namespace std;

// fはレベルNを下からX枚食べた時に食べるパティの量を返す
long f(int N, long X, long a[], long p[]){
    if(N == 0){
        return X <= 0 ? 0 : 1;
    } 
    else if (X <= 1 + a[N-1])
    {
        return f(N-1, X-1, a, p);
    }
    else
    {
        return p[N-1] + 1 + f(N-1, X -a[N-1] -2, a, p);
    }
}

int main(void){
    int N;
    long X;
    cin >> N >> X;
    long a[N+1], p[N+1];
    a[0] = 1, p[0] = 1;
    for(int i=1; i<N+1; i++){
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }
    cout << f(N, X, a, p) << endl;
    return 0;
}