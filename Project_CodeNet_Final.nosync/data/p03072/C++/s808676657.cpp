        #include <bits/stdc++.h>
        #define REP(i, n) for(int i = 0;i < n;i++)
        using namespace std;
        int main()
        {
        int n;
        cin>>n; int cnt=1;
        vector<int> h(n,0);
        REP(i,n)
        {
            cin >> h[i];
        }
            int d=h[0];
        for(int i=0; i<n-1; i++)
        {
           d=max(d,h[i]);
           if(d<=h[i+1]) ++cnt;
        }
        cout<<cnt<<endl;
        }