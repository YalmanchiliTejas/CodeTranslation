#include <bits/stdc++.h>

using namespace std;

int ar[200010];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int a = 0, b = n - 1;
    for(int i = n - 1; i >= 0; i-= 2) {
        cout << ar[i] << ' ';
    }
    int i;
    if(n % 2 == 0)
        i = 0;
    else
        i = 1;
    for(i; i < n; i+= 2) {
        cout << ar[i] << ' ';
    }


	return 0;
}
