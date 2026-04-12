#include <iostream>

using namespace std;
using ll = long long;


const int MAX_N = 1;


int a, b, c, x, y;


int solve()
{   
    int sum1 = a * x + b * y;
    int sum2 = c * 2 * max(x, y);
    int sum3;
    if(x > y) sum3 = c * 2 * y + (x - y) * a;
    else sum3 = c * 2 * x + (y - x) * b;

    return min(sum1, min(sum2, sum3));
    
}

int main()
{
    cin >> a >> b >> c >> x >> y;
    
    cout << solve() << endl;


    return EXIT_SUCCESS;
}