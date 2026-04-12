
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using ll = long long int;
using ul = unsigned long long int;
const ll LL_MAX (1LL<<60);
const ll MOD (1000000007);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c;
    cin >> c;

    bool v(false);

    switch (c)
    {
        case 'a':
        {
            v = true;
            break;
        }
        case 'e':
        {
            v = true;
            break;
        }
        case 'i':
        {
            v = true;
            break;
        }
        case 'o':
        { 
            v = true;
            break;
        }
        case 'u':
        {
            v = true;
            break;
        }
        default:
            break;
    }

    if (v)
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;

    return 0;
}
