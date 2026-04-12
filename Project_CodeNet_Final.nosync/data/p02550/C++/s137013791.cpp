#include<bits/stdc++.h>
#define ll long long
#define mxn 200005
using namespace std;
ll ara[mxn];
bool vis[mxn];
int main()
{
    ll n, x, m;
    scanf("%lld %lld %lld", &n, &x, &m);
    if(m==1)
    {
        printf("0\n");
        return 0;
    }
    ara[1]= x;
    for(int i=2; i<=2*m; i++)
    ara[i]= (ara[i-1]*ara[i-1])%m;
    ll st= 0, sum= 0;
    vector<ll>vec;
    for(int i=1; ;i++)
    {
        if(!vis[ ara[i] ])vis[ ara[i] ]= 1;
        else
        {
            ll x= ara[i];
            i--;
            while(ara[i]!=x)vec.push_back(ara[i]), i--;
            i--;
            st= i;
            vec.push_back(x);
            reverse(vec.begin(), vec.end());
            for(int j=0;j<vec.size(); j++)sum+= vec[j];
            break;
        }
    }
    ll res= 0;
    for(int i=1; i<=min(st, n); i++)res+= ara[i];
    n-= min(st, n);
    res+=(n/vec.size())*sum;
    for(int i=0; i<(n%vec.size()); i++)res+= vec[i];
    printf("%lld\n", res);
    return 0;
}
