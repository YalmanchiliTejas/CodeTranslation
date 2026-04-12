        #include<bits/stdc++.h>
        using namespace std;
        #include <ext/pb_ds/assoc_container.hpp>
        #include <ext/pb_ds/tree_policy.hpp>
        using namespace __gnu_pbds;
        #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
        #define ll long long
        #define int long long
        #define lb long double
        #define f(i,a,b) for(int i=(a);i<=(b);i++)
        #define fd(i,a,b) for(int i=a;i>=b;i--)
        #define vi vector<int>
        #define mii map<int,int>
        #define pii pair<int,int>
        #define si set<int>
        #define pb push_back
        #define mk make_pair
        #define fi first
        #define se second
        #define fv(i,v) for(auto i=v.begin();i!=v.end();++i)
        #define fdv(i,v) for(auto i=v.rbegin();i!=v.rend();++i)
        #define print(a,n) f(i,1,n) cout<<a[i]<<" "; cout<<endl;
        #define printv(v) for(auto iv: v) cout<<iv<<" "; cout<<endl;
        #define all(v) v.begin(),v.end()
        #define r(a,n) ll a[n+1]; f(i,1,n) cin>>a[i];
        #define pi 3.141592653589793238
        const int inf=1e18;
        const int mod=1e9+7;
       /* const int maxi=100001;
        int parent[maxi];
        int size[maxi];
        const int MAXN=2345;
        int spf[MAXN];
        int popcount[MAXN];
        int d[maxi+1];
        int dp[maxi+1];
        //vector<bool> vis(MAXN);

        ll power(ll x, unsigned ll y)
        {
            ll res = 1;
            while (y > 0)
            {
                if (y & 1)
                    res = res*x;
                y = y>>1;
                x = x*x;
            }
            return res;
        }

        bool isPrime(int n)
        {
            if (n <= 1)
                return false;
            if (n <= 3)
                return true;

            if (n % 2 == 0 || n % 3 == 0)
                return false;

            for (int i = 5; i * i <= n; i = i + 6)
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;

            return true;
        }
        void sieve()
        {
            spf[1] = 1;
            for (int i=2; i<MAXN; i++)
                spf[i] = i;
            for (int i=4; i<MAXN; i+=2)
                spf[i] = 2;
            for (int i=3; i*i<MAXN; i++)
            {
                if (spf[i] == i)
                {
                    for (int j=i*i; j<MAXN; j+=i)
                        if (spf[j]==j)
                            spf[j] = i;
                }
            }
        }

        int lcm(int a, int b)
        {
            return (a*b)/__gcd(a,b);
        }

        bool sortbysec(const pair<int,int> &a,
                      const pair<int,int> &b)
        {
            if(a.fi==b.fi)return (a.second < b.second);
            return a.fi<b.fi;
        }

        unsigned int countSetBits(unsigned int n)
        {
            unsigned int count = 0;
            while (n) {
                count += n & 1;
                n >>= 1;
            }
            return count;
        }

        string decTobin(int n)
        {
            string s={};
            while(n>0)
            {
                if(n%2==0)s.append("0");else s.append("1");
                n/=2;
            }
            return s;
        }

        void rev(string& a,int l)
        {
            f(i,0,l)
            {
                if(a[i]==0)a[i]=1;
                else a[i]=0;
            }
            reverse(a.begin(),a.begin()+l+1);
        }

        void make_set(int v) {
            parent[v] = v;
            size[v] = 1;
        }

        int find_set(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }

        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                if (size[a] < size[b])
                    swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
*/
        signed main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            int t=1;
            //cin>>t;
            while(t--)
            {
                int n;
                cin>>n;
                r(a,n);
                ll sum=0;
                ll div=0;
                fd(i,n-1,1)
                {
                    sum+=a[i+1];
                    sum%=mod;
                    div=div+(a[i]*sum)%mod;
                    div%=mod;
                }
                cout<<div<<endl;
            }
        }
