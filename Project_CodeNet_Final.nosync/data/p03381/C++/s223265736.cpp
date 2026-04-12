        #include <bits/stdc++.h>
        using namespace std;
        #define int long long

        signed main() {
            int n,a;
            cin>>n;
            pair<int,int> x[n];
            for(int i=0;i<n;i++){
                cin>>a;
                x[i]=make_pair(a,i);
            }

            sort(x,x+n);
            int ans[n];
            for(int i=0;i<n;i++){
                if(i<n/2)ans[x[i].second]=x[n/2].first;
                else ans[x[i].second]=x[n/2 -1].first;
            }
            for(int i=0;i<n;i++)cout<<ans[i]<<endl;



         return 0;

        }
