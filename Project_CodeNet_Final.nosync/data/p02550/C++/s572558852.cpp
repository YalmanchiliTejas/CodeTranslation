#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,X,M;
    cin >> N >> X >> M;
    ll cur=X%M, ans=X%M;
    map <ll, ll> pos;
    vector <ll> sums(min(N,M)+2,0);
    sums[1]=cur;
    pos[cur]=1;
    for (int i=2; i<=N; ++i)
    {
        cur = (cur*cur)%M;
        sums[i]=(sums[i-1]+cur);
        if (pos.find(cur)!=pos.end())
        {   
            int prev=pos[cur];
            int len=(i-prev);
            ll rem = N-i+1;
            ans  = ans+ (((rem/len)) * ((sums[i-1]-sums[prev-1])));
            rem = rem%len;
            ans = (ans+ sums[prev+rem-1]-sums[prev-1]);
            break;
        }
        ans=sums[i];
        pos[cur]=i;
    }
    cout << ans << "\n";
    return 0;
}