#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int H[N];
    for (int i=0; i<N; i++) {
        cin >> H[i];
    }

    int nagame = 1;
    int high = H[1];

    for (int i=1; i<N; i++) {
        if (high < H[i-1]) {high = H[i-1];}
        if (H[i-1] <= H[i] && high <= H[i]) {
            nagame += 1;
        }
    }

    cout << nagame;

    return 0;
}   
