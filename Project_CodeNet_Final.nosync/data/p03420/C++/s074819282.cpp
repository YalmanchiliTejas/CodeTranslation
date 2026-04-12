#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)


i64 n;
i64 k;

int main()
{
    cin >> n >> k;

    i64 result = 0;

    if(k == 0)
    {
        cout << n * n << endl;
        return 0;
    }

    for(i64 b = k + 1;b <= n;b++)
    {
        i64 one = b - k;
        i64 cou = (n - k) / b;

        result += cou * one;

        i64 a = k + b * cou;
        result += min(n - a + 1, b * cou + b - a);
    }

    cout << result << endl;
}