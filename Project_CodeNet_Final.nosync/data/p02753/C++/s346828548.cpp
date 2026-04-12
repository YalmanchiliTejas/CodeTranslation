#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef double d;
typedef pair<int, int> pr;
typedef priority_queue<int> p_int_max;
typedef priority_queue<int, vector<int>, greater<int>> p_int_min;

char c;
int a, b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    rep(i, 3)
    {
        cin >> c;
        if (c == 'A')
            a++;
        else if (c == 'B')
            b++;
    }
    if (a && b)
        cout << "Yes\n";
    else
        cout << "No\n";
}