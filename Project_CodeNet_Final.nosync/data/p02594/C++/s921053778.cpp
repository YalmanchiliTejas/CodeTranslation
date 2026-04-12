#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int main()
{
    int n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else
        cout<<"No";

}
