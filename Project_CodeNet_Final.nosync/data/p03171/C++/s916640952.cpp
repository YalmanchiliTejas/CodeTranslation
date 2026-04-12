    #include<bits/stdc++.h>
    using namespace std;
     
     
    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define loop(i, a, b) for(int i = (a); i < (b); i++)
    #define loopb(i, a, b) for(int i = (a); i > (b); --i)
     
    typedef pair <int,int> ii;
    typedef vector <int> vi;
    typedef vector <ii> vii;
    typedef vector <ll> vl;
     
    const int mod = 1e9+7;
    const ll inf = 2e18+5;
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin>>n;
        vl a(n);
        loop(i,0,n) cin>>a[i];

        ll dp[3005][3005]; //dp[i][j] is the answer when interval of [i,j] is remaining. So our final answer will be [0,n-1]

        for(int i=n-1; i>=0; i--){
            for(int j=i; j<=n-1; j++){
                if(i==j)
                    dp[i][j] = a[i];
                else
                    dp[i][j] = max(a[i] - dp[i+1][j] , a[j] - dp[i][j-1]);    
            }
        }

        cout<<dp[0][n-1];

        return 0;

}