#include <bits/stdc++.h>

using namespace std;

// Function come here..
bool foo(int n)
{
    return (n == 7 || n == 5 || n == 3);
}

int main(int argc, char **argv)
{
    // Problem solution come here...
    int n;
    cin >> n;

    if (foo(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}