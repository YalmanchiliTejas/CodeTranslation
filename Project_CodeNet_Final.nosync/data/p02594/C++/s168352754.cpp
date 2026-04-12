#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int mod = 1000000007;

int main()
{
    IOS
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int X;
        cin >> X;
        if (X >= 30)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}