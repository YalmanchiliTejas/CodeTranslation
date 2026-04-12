#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    const int MAXC = max(X,Y)*2;
    int minvalue = INT_MAX;
    for (int c = 0; c <= MAXC; ++c)
    {
        int value = 2 * c * C;
        int x = X - c;
        int y = Y - c;
        value += A * max(x, 0) + B * max(y, 0);

        if(minvalue>value){
            minvalue = value;
        }
    }
    cout << minvalue << endl;
}