#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <climits>
using namespace std;


int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    
    int result = INT_MAX;
    for (int i = 0; i <= 100000; i++) {
        int sum = 2 * C * i + max(0, X - i) * A + max(0, Y - i) * B;
        result = min(result, sum);
    }
    
    cout << result << endl;
}