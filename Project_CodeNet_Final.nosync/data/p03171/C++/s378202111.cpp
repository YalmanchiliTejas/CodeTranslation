          #include <bits/stdc++.h>
          using namespace std;
          #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
          #define M_PI 3.14159265358979323846
          #define data data_
          #define ff first
          #define ss second
          int const N = 3009;
          long long dp[N][N];
          long long a[N];
          long long fun(int i,int j)
          {
               if(i==j)
                    return a[i];
               else if(j == i+1)
                    return (a[i] > a[j] ? (a[i]- a[j]) : (a[j] - a[i]));
               else if(dp[i][j] != -1)
                    return dp[i][j];
               else
                    return dp[i][j] = max(a[i] + min(-a[i+1] + fun(i+2,j), -a[j] + fun(i+1,j-1)), 
                                   a[j] + min(-a[i] + fun(i+1,j-1), -a[j-1] + fun(i,j-2)));
          }
          int main()
          {
          // clock_t begin = clock();
          // #ifndef ONLINE_JUDGE
          // freopen("input.txt", "r", stdin);
          // freopen("output.txt", "w", stdout);
          // #endif
          tani_nachi_ke  

          int n;
          cin >> n;
          for(int i = 1; i <= n; i++)
               cin >> a[i];
          memset(dp, -1 ,sizeof(dp));
          cout << fun(1, n) << endl;




          // #ifndef ONLINE_JUDGE 
          // clock_t end = clock();
          // cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
          // #endif 
          // return 0;
          }