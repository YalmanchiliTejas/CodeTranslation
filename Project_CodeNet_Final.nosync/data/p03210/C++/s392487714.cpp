#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    if (x==3||x==5||x==7)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
