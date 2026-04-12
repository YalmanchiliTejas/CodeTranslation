#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N, S[202020];
ll i, j, k, l,ans;
ll mk[202020];

int main(){
    scanf("%lld", &N);
    fornum(i,0,N){
        scanf("%lld", &S[i]);
    }
    ans = 0;
    fornum(i,1,N){
        ll li = 0,ri=N-1;
        ll ct = 0;
        while(i<=ri+i&&li<N-i&&li!=ri&&mk[li]!=i&&mk[ri]!=i){
            ct += S[li];
            ct += S[ri];
            mk[li] = i;
            mk[ri] = i;
            li += i;
            ri -= i;
            if(ct>ans){
                ans = ct;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}