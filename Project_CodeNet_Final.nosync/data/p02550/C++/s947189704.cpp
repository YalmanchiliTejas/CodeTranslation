/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
    Mbak Seulgi Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
ll dp[200200], arr[200200];
map<int,int> mp;
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    ll a;
    cin >> a >> x >> m;
    ll seulgi = x;
    ll now = x;
    i = 1;
    mp[now] = i;
    dp[i] = now;
    a--;
    while(a--) {
        now *= now;
        now %= m;
        i++;
        dp[i] = now;
        seulgi += now;
        if(mp[now] > 0) {
            int last = mp[now] + 1;
            int cnt = 1;
            for(j=last;j<=i;j++) {
                arr[cnt] = arr[cnt-1] + dp[j];
                cnt++;
            }
            cnt--;
            ll bagi = a / cnt;
            seulgi += bagi * arr[cnt];
            a %= cnt;
            seulgi += arr[a];
            cout << seulgi << endl;
            return 0;
        }
        mp[now] = i;
    }
    cout << seulgi << endl;
    return 0;
}
