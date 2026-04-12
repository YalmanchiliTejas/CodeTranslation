/* Atcoder abc158a
 * See tasks at: https://atcoder.jp/contests/abc158/tasks/abc158_a
 */
#include <iostream>
#include <vector>
#include <algorithm>

#define until(symbol, max) for (int symbol = 0; (symbol) < (max); (symbol)++)

using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;

    if (s == "AAA"s || s == "BBB"s)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    
    return 0;
}
