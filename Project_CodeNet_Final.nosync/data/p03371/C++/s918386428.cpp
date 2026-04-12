#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
using namespace std;

int GetMinimum(int A, int B, int C, int X, int Y){
    int maxnab = max(2*X, 2*Y);
    int minsum = INT_MAX;
    for(int nab=0; nab<=maxnab; nab+=2){
        int na = X - nab/2;
        int nb = Y - nab/2;
        if (na<0) na=0;
        if (nb<0) nb=0;
        int sum = A * na + B * nb + C * nab;
        if(sum < minsum) minsum = sum;
    }
    return minsum;
}

int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    auto n = GetMinimum(A,B,C,X,Y);
    cout << n << endl;
    return 0;
}