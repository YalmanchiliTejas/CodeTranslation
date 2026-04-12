#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>

#define ll long long
#define sz 205

using namespace std;

int main()
{
    ll sum=0,x;

    for(ll i=1;i<=3;i++)
    {
        scanf("%lld",&x);

        sum=(sum*10)+x;
    }

    if(sum%4==0)
        printf("YES\n");

    else
        printf("NO\n");

    return (0);
}


