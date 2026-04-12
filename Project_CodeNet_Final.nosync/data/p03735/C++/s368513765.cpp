#include<bits/stdc++.h>
using namespace std;
int N;
long long v[404040];
long long solve1(int mini, int maxi)
{
    int minA = v[mini];
    int maxB = v[maxi];
    int minB = v[mini^1];
    int maxA = v[maxi^1];
    for(int i=0; i<N; ++i)
    {
        int v1 = v[2*i], v2 = v[2*i+1];
        if(v1>v2) swap(v1, v2);
        minB = min(minB, v2);
        maxA = max(maxA, v1);
    }
    return 1LL * (maxA-minA) * (maxB-minB);
}
long long solve2(int mini, int maxi)
{
    int minv = min(v[maxi^1], v[mini^1]);
    int maxv = max(v[maxi^1], v[mini^1]);
    
    set<pair<int, int> > S;
    for(int i=0; i<N; ++i)
    {
        if(mini/2 == i || maxi/2 ==i) continue;
        S.insert(make_pair(max(v[2*i],v[2*i+1]), i));
    }
    int ans = maxv - minv;
    if(!S.empty())
    {
        ans = max(maxv, S.rbegin()->first) - min(minv, S.begin()->first);
        for(int i=0; i<S.size(); ++i)
        {
            pair<int, int> x = *S.rbegin();
            int xf = x.first;
            x.first ^= (v[x.second*2]^v[x.second*2+1]);
            if(xf <= x.first)
                break;
            S.erase(*S.rbegin()); S.insert(x);
            ans = min(ans,
                max(maxv, S.rbegin()->first) - min(minv, S.begin()->first));
        }
    }
    return 1LL*(v[maxi]-v[mini])*ans;
}
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%lld%lld", v+(2*i), v+(2*i)+1);
    
    int minind = min_element(v, v+2*N) - v;
    int maxind = max_element(v, v+2*N) - v;
    long long ans = solve1(minind, maxind);
    if((minind^1) != maxind) ans = min(ans, solve2(minind, maxind));
    
    printf("%lld\n", ans);
}