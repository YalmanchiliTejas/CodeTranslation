#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    

    rep(i, 4)
    {
        string order;

        if (i == 0) order = "SS";
        else if (i == 1) order = "SW";
        else if (i == 2) order = "WW";
        else if (i == 3) order = "WS";

        rep(j, n)
        {
            if (order[j] == order[j + 1])
            {
                if (s[(j + 1)%n] == 'o')
                    order.append("S");
                else
                    order.append("W");
            }
            else
            {
                if (s[(j + 1)%n] == 'o')
                    order.append("W");
                else
                    order.append("S");
            }
        }

        if (order[n] == order[0] and order[n+1] == order[1])
        {
            cout << order.substr(0, n) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}