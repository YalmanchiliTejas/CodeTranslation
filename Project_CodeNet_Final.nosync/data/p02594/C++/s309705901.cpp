#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    long long int x;
    cin>>x;
    if(x>=30)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
