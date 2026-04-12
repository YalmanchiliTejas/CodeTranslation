#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N, K;
    cin >> N >> K;
    ll res = 0;
    for(int b=K+1; b<=N; b++){
        res += (N/b)*(b-K);
        if(N%b>=K) res += (N)%b-K + (K==0? 0:1);
    }
    cout<<res<<endl;

    return 0;
}