#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int n;
int a[200000];
int main()
{
    scanf("%d" , &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d" , &a[i]);
    }
    vector<int> b;
    for(int i = n - 1; i >= 0; i -= 2)
    {
        b.pb(a[i]);
    }
    for(int i = n % 2; i < n; i+=2)
        b.pb(a[i]);
    for(int i = 0; i < n; i++)
        printf("%d " , b[i]);

    return 0;
}
