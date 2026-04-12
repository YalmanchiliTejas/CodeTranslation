#include<bits/stdc++.h>
using namespace std;

using ll=long long int;
ll n,x,m;

int main()
{
    cin>>n>>x>>m;
    vector<ll>cnt(m,0);
    queue<ll>rem;
    ll idx=1,sum=x,ans=0,next=(x*x)%m,loop=0;
    cnt[x]=idx;
    rem.push(x);
    while(1)
    {
        if (cnt[next] != 0) 
            break;
        cnt[next] = ++idx;
        rem.push(next);
        sum += next, next = (next * next) % m;
    }
    for (auto i = 1; i < cnt[next]; i++) 
    {
        ans += rem.front();
        rem.pop();
    }

    loop = rem.size(), n -= (cnt[next] - 1),
    ans += (n / loop) * (sum - ans);
    for (auto i = 0; i < n % loop; i++) 
    {
        ans += rem.front();
        rem.pop();
    }
    cout << ans << endl;
}

