    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int n; int naj = 0;
        cin >> n;
     
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int v; cin >> v;
            if (v >= naj) ++res, naj = v;
        }
     
        cout << res << '\n';
    }