
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define f first
    #define s second
    #define sz(x) (int)x.size()
    #define all(x) x.begin(), x.end()

    using namespace std;
    using namespace __gnu_pbds;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
    template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
    template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
    template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

    int n;
    vector<ll> a;
    pair<ll, ll> dp[3004][3004];

    pair<ll, ll> score(int l, int r)
    {
        if(l > r)
            return make_pair(0,0);
        if(dp[l][r].first != -1)
        {
            //cout << l << " " << r << ": " << dp[l][r] << endl;
            return dp[l][r];
        }
        if(l == r)
        {
            dp[l][r] = make_pair(a[l], 0);
        }

        ll levi = score(l+1, r).second + a[l];
        ll desni = score(l, r-1).second + a[r];

        if(levi > desni)
        {
            dp[l][r].first = levi;
            dp[l][r].second = score(l+1, r).first;
        }
        else
        {
            dp[l][r].first = desni;
            dp[l][r].second = score(l, r-1).first;
        }
        //cout << l << " " << r << ": " << dp[l][r]<< endl;
        return dp[l][r];
    }

    int main()
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            ll pom;
            cin >> pom;
            a.push_back(pom);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dp[i][j] = make_pair(-1, 0);
            }
        }

        pair<ll,ll> pom = score(0, n-1);
        cout << pom.first - pom.second << endl;

        return 0;
    }
