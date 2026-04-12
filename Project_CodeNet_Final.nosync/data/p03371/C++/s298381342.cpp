#include <bits/stdc++.h>
using namespace std;

int main()
{
    long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int a_num=-1;
    int b_num=-1;
    int c_num=-1;
    long minval = LONG_MAX;
    for (int i=0; i<=2*max(X, Y); i+=2)
    {
        const long zero = 0;
        c_num = i;
        a_num = max(zero, X-i/2);
        b_num = max(zero, Y-i/2);
        minval = min(minval, A*a_num+B*b_num+C*c_num);
    }
    cout << minval << endl;
    //cout << a_num << " " << b_num << " " << c_num << endl;
    
}