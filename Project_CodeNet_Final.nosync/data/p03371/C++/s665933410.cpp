#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long max(long long a, long long b)
{
    if (a >= b){
        return a;
    }
    else {
        return b;
    }
}

long long min(long long a, long long b, long long c) 
{
    if (a <= b) {
        if (a <= c){
            return a;
        }
        else {
            return c;
        }
    }
    else {
        if (b <= c) {
            return b;
        }
        else {
            return c;
        }
    }
}

int main()
{
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans_1, ans_2, ans_3, ans;
    long long  z;
    long long D = 1000000;

    ans_1 = a*x+b*y;
    ans_2 = 2*c*max(x,y);

    if (min(x,y,D) == x) {
        z = b;
    }
    else {
        z = a;
    }
    ans_3 = 2*c*min(x,y,D) + z*(max(x,y)-min(x,y,D));

    ans = min(ans_1,ans_2,ans_3);

    cout << ans << endl;

    return 0;
}