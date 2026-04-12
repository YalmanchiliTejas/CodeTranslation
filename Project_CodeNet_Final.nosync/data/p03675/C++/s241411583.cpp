#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define All(v) v.begin(),v.end()
#define mod 1000000007
#define pi 3.14159265358979323
using namespace std;
int a[200005],b[200005];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    int c1 = 1;
    int c2 = n;
    for(int i=n;i>=1;i--)
    {
        if(n%2 == i%2)
            b[c1++] = a[i];
        else
            b[c2--] = a[i];
    }
        for(int i=1;i<=n;i++)
            cout << b[i] << " ";



    return 0;
}
