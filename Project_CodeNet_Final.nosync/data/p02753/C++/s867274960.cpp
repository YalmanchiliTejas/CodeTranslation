#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int main()
{
    abdelrahman010
    string s;
    cin >> s;
    bool f1 = false , f2 = false;
    for(auto &i : s)
    {
        f1 |= (i == 'A');
        f2 |= (i == 'B');
    }
    if(f1 && f2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}