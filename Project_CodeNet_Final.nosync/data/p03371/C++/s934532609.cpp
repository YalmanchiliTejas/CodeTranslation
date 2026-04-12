#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>

#define div1 1000000007

using namespace std;

int main(void)
{
    long long A, B, C, X, Y, sum1, sum2, sum3;

    cin >> A >> B >> C >> X >> Y;

    if(X > Y){
        sum1 = A*X + B*Y;

        sum2 = C*Y*2 + A*(X-Y);

        sum3 = C*X*2;
    }

    else{
        sum1 = A*X + B*Y;

        sum2 = C*X*2 + B*(Y-X);

        sum3 = C*Y*2;
    }

    if(sum1<=sum2 && sum1<=sum3) cout << sum1 << endl;
    else if(sum2<=sum1 && sum2<=sum3) cout << sum2 << endl;
    else cout << sum3 << endl;

    return 0;
}