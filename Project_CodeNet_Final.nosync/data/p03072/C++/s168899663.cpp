#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,hmax;
    int h[100];
    cin>>n;
    for (size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    hmax=h[0];
    int les=1;
    for (size_t i = 1; i < n; i++) {
        if (hmax<=h[i]) {
            les++;
            hmax=h[i];
        }
    }
    std::cout << les << '\n';
}
