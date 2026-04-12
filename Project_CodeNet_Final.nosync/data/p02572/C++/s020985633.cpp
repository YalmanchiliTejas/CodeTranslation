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
        int32_t main()
        {
            tani_nachi_ke  
            
            
            int n;
            cin >> n;
            int a[n], sum[n+10] = {0};
            int const mod = 1e9 + 7;
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
                sum[i+1] += sum[i] + a[i];
                sum[i+1] %= mod;
            }
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                ans += sum[i]*a[i];
                ans %= mod;
            }
            cout << ans << '\n';

           return 0;
        }
          