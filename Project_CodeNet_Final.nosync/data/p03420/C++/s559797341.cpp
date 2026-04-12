    #include <bits/stdc++.h>
    #define mp make_pair
    #define F first
    #define S second
    #define mem(a) memset(a, 0, sizeof(a))
    #define memm(a) memset(a, -1, sizeof(a))
    #define INF 0x3f3f3f3f
    #define maxn 1000005
    using namespace std;
    typedef long long LL;
    typedef pair <int,int> PP;
    LL n,k;
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        while(cin >> n >> k){
            LL ans=0;
            if(k==0){cout << n*n << endl;continue;}
            for(LL i=k+1;i<=n;i++){
                ans+=n/i*(i-k)+max(1ll*0,n%i-k+1);
            }
            cout << ans << endl;
        }
        return 0;
    }