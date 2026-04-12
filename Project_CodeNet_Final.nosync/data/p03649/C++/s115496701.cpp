#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll A[100];
ll ans = 0;
bool F;

int main()
{
    scanf("%lld",&N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld",&A[i]);
    }
    while(1)
    {
        F = false;
        for(int i = 0; i < N; i++)
        {
            if(A[i] + ans >= N)
            {
                F = true;
                ll mem = (A[i] + ans) / N;
                A[i] -= mem * (N + 1);//自分の分を減らす
                ans += mem;
            }
        }
        if(!F)break;
        //printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}
