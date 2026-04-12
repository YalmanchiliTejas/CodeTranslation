#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    int max_height=INT_MIN;
    int count=0;

    for (int i=0;i<=n-1;i++)
    {
        int a;
        cin >> a;
        if (a>=max_height)
        {
            count++;
        }
        max_height=max(max_height,a);
    }

    cout << count << endl;
    return 0;
}