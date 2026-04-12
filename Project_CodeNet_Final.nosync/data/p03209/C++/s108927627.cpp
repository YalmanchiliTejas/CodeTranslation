#include <iostream>
#include <list>
using namespace std;

typedef long long ll;

ll layers[51];
ll patties[51];

list<ll> burger;

int main()
{
    ll n, x;
    cin >> n >> x;
    layers[0] = 1;
    patties[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        layers[i] = 2 * layers[i - 1] + 3;
        patties[i] = 2 * patties[i - 1] + 1;
    }
    burger.push_back(n);
    ll result = 0;
    while (x > 0 && burger.size() > 0)
    {
        while (burger.size() > 0 && (burger.back() == -1 || layers[burger.back()] <= x))
        {
            if (burger.back() == -1) {x--; burger.pop_back(); continue;}
            x -= layers[burger.back()];
            result += patties[burger.back()];
            burger.pop_back();
        }
        if (burger.size() == 0 || x == 0) {break;}
        ll last1 = burger.back();
        burger.pop_back();
        burger.push_back(-1);
        burger.push_back(last1 - 1);
        burger.push_back(0);
        burger.push_back(last1 - 1);
        burger.push_back(-1);
    }
    cout << result << endl;
}
