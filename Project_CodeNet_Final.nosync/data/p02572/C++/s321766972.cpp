#include <math.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long M[N],total=0,sum=0;
    for (int i = 0; i < N;i++){
        cin >> M[i];
        total += M[i];
        total = total % 1000000007;
    }
        for (int i = 0; i < N - 1; i++) {
            if (total >= M[i]) total -= M[i];
            else
                total = total + 1000000007 - M[i];
            sum+=(M[i] * total) % 1000000007;
            sum = sum % 1000000007;
             }
             cout << sum << endl;
             return 0;
}
