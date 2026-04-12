        #include <bits/stdc++.h>
        using namespace std;
        #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
        #define M_PI 3.14159265358979323846
        #define data data_
        #define ff first
        #define ss second
        #define pb push_back
        #define ld long double
        #define int long long
        #define print(t) cout << "Case #" << t << ": ";

        int const N = 200009;
        map<pair<int,int>,int> mp;
        int a[N];
        int const inf = 1e15;

        int fun(int n, int k)
        {

            if(k < 0 || n < 0)
                return -inf;
            else if(k == 1)
            {
                int mx = -inf;
                for(int i = 1; i <= n; i++)
                    mx = max(mx, a[i]);
                return mx;
            }
            else if(mp.find({n, k})!=mp.end())
                return mp[{n,k}];
            else
            {
               
                int ans = -inf;
                if((k-1) <= (n-1)/2)
                    ans = max(ans, a[n] + fun(n-2,k-1));
                if(k <= n/2)
                    ans = max(ans, fun(n-1, k));
                return mp[{n,k}] = ans;
            }
        }

    
       

        int32_t main()
        {
            tani_nachi_ke  
            
           int n;
           cin >> n;
           for(int i = 1; i <= n; i++)
            cin >> a[i];
       
        cout << fun(n, n/2) << endl;
            





           return 0;
        }
          