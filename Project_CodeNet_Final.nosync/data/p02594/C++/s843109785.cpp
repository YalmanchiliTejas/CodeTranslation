#include<iostream>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    long long int x;
    cin >> x;
    if(x >= 30)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}