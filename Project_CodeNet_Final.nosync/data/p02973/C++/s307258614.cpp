      #pragma comment(linker, "/stack:200000000")
        #pragma GCC optimize ("Ofast")
        #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
         
         
        #include <iostream>
        #include <iomanip>
        #include <sstream>
        #include <cstring>
        #include <vector>
        #include <deque>
        #include <queue>
        #include <set>
        #include <map>
        #include <valarray>
        #include <iterator>
        #include <functional>
        #include <limits>
        #include <algorithm>
        #include <numeric>
        #include <cmath>
        #include <cassert>
        #include <unordered_map>
        #include <stack>
        using namespace std;
        #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
         #define trace(x) cerr << #x << ": " << x << " " << endl;
     
        typedef int64_t ll;
     
        #define endl '\n'
        #define int ll
        ll mod=1e9+7;
        ll mod1=1e9+5;
        ll power(ll a,ll b)
        {
            if(b==0) return 1;
            else if(b%2==0)
                return power((((a%mod)*(a%mod))%mod),b/2)%mod;
            else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
        }
       
        
        int32_t main()
        {
            IOS
           
            
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        multiset<int> m;
        int count=0;
        for(int i=0;i<n;++i)
        {
            // for(auto j:m)
            //     cout<<j<<" ";
            // cout<<endl;
            if(m.empty())
            {
                count++;
                m.insert(a[i]);
                continue;
            }

            auto j=m.lower_bound(a[i]);
            if(j==m.begin())
            {
                m.insert(a[i]);
                count++;
                continue;   
            }
            j--;

            if(*j<a[i])
            {
                m.erase(j);
                m.insert(a[i]);
                continue;
            }
            else
            {
                m.insert(a[i]);
                count++;
            }
        }
        cout<<count;
        

        }
