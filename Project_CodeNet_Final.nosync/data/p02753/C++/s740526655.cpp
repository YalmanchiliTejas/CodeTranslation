#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll mod = 1e9 + 7;
const int N = 1e5 + 10, M = 1e3 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;

#define pi acos(-1)

int main()
{
    string s;
    cin >> s;
    int f1 =0, f2 = 0;
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == 'A')
            f1++;
        else
        {
            f2++;
        }
        
    }
    if(f1 && f2)
        puts("Yes");
    else
    {
        puts("No");
    }
    
    return 0;
}