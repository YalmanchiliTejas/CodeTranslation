#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <list>
#include <string>
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;

int main()
{
    int N;
    cin >> N;

    int ret = 1;
    int Hi;
    cin >> Hi;
    REP(i, N - 1)
    {
        int Hi2;
        cin >> Hi2;
        if (Hi <= Hi2)
        {
            ret++;
            Hi = Hi2;
        }
    }

    cout << ret << endl;
}

void cheatsheet()
{
    // loop
    // vector<int> vec(10);
    vector<int> vecloop;
    REP(i, 10)
    {
        vecloop.push_back(i);
    }

    // swap
    int a = 1;
    int b = 5;
    swap(a, b); // -> a = 5, b = 1

    // sort
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(arr, arr + 9, greater<int>()); // 9 8 7 6 5 4 3 2 1

    // lower
    vector<int> vec(arr, end(arr));
    sort(vec.begin(), vec.end());
    cout << lower_bound(vec.begin(), vec.end(), 2)[0]; // 2

    // map
    map<Pll, ll> m;
    m[Pll(10, 100)] = 100;
}