/*我是萌新*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <iomanip> 
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s;
    while (cin >> s)
    {
        int a = 0, b = 0;
        for (int i = 0; i < 3; i++)
        {
            if (s[i] == 'A')a++;
            else b++;
        }
        if (a == 3 || b == 3)cout << "No\n";
        else cout << "Yes\n";

    }
}

