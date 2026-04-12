#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<cstdio>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007

#define ARRAY_MAX 55

ll n,x,ans = 0;
ll p[ARRAY_MAX];
ll b[ARRAY_MAX];
ll cnt[ARRAY_MAX];


void dfs(ll now,ll sum){
    //レベルnow
    sum++;
    if(now == 0){
        ans++;
    }
    if(sum == x){
        //合計に達した
        return;
    }else if(sum + cnt[now-1] < x){
        //まだ足せる
        sum += cnt[now-1];
        ans += p[now-1];

        sum++;
        ans++;
        if(sum == x){
            return;
        }else{
            if(sum + cnt[now-1] < x){
                sum += cnt[now-1];
                ans += p[now-1];
            }else{
                dfs(now-1,sum);
            }
            sum++;
            return;
        }

    }else{
        //now-1までのなかでxに達する
        dfs(now-1,sum);
    }




}



int main(){

    cin >> n >> x;
    p[0] = 1;
    b[0] = 0;
    cnt[0] = 1;

    REP(i,50){
        p[i+1] = 2*p[i] + 1;
        b[i+1] = 2*b[i] + 2;
        cnt[i+1] = 2*cnt[i] + 3;
    }
    dfs(n,0);
    cout << ans << endl;

    
    return 0;
}