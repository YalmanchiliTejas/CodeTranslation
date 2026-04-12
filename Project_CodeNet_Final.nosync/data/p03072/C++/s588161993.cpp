#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, *a, b=0, ans=0;
    cin >> n;
    a=new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        ans=max(ans,a[i]);
        if(ans<=a[i])
            b++;
    }
    cout << b <<'\n';
}