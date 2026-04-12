#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N, M;
    cin >> N >> M;
    ll ai, bi;
    vector<set<ll>> g(N, set<ll>());
    for(int i=0;i<M;i++){
        cin >> ai >> bi;
        g[ai-1].insert(bi-1);
        g[bi-1].insert(ai-1);
    }
    vector<ll> pattern(N-1, 0);
    iota(pattern.begin(), pattern.end(), 1);
    ll res=0;
    do{
        if(g[0].count(pattern[0])==0) continue;
        bool isGood = true;
        for(int i=0; i<N-2; i++){
            isGood = (g[pattern[i]].count(pattern[i+1])>0);
            if(!isGood) break;
        }
        if(isGood) res++;
    }while(next_permutation(pattern.begin(), pattern.end()));

    cout<<res<<endl;

    return 0;
}