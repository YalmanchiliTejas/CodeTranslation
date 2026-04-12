#include<bits/stdc++.h>


#define ll long long



#define biggestFactor (n)      for (ll j = 2; j <= sqrt(n); j++){if (n % j == 0){cout << n / j << "\n";break;}}
                               //First find smallest factor and then divide that factor and the answer itself is biggest factor
                          
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    cin >> x;
    if (x >= 30)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }
	return 0;
}
