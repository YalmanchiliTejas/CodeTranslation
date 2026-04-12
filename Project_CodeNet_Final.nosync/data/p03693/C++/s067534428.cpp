#include<bits/stdc++.h>
using namespace std;

#define lld long long int
#define llu unsigned long long

int main()
{
    //freopen("input.txt", "w", stdin);

    int r,g,b,res = 1;

    while(cin>>r>>g>>b)
    {
        res = ((r*10+g)*10)+b;

        if(res % 4)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
