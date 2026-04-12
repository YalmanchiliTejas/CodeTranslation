#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    cout<<(n/15)*(15*800-200)+(n%15)*800<<endl;
    return 0;
}