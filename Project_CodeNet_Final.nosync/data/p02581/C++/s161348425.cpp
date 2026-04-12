#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;

const int nax = 2005;

int dp[nax][nax];
int a[nax * 3];
int n;
int booost = 0;

int maxi[nax];
int glomax = 0;

vector<pair<pair<int,int> , int> > maybe;

int main()
{
    cin>>n;
    for(int i=1;i<=3*n;i++) cin>>a[i];
    if(n == 1)
    {
        if(a[1] == a[2] && a[2] == a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=0;i<nax;i++)
    {
        for(int j=0;j<nax;j++)
        {
            dp[i][j] = - 1e9;
        }
        maxi[i] = -1e9;
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=i+1;j<=5;j++)
        {
            int v1 = a[i];
            int v2 = a[j];
            vector<int> rest;
            for(int k=1;k<=5;k++)
            {
                if(k != i && k != j) rest.pb(a[k]);
            }
            if(v1 > v2) swap(v1,v2);
            if(rest[0] == rest[1] && rest[1] == rest[2]) dp[v1][v2] = 1;
            else dp[v1][v2] = 0;
            maxi[v1] = max(maxi[v1],dp[v1][v2]);
            maxi[v2] = max(maxi[v2],dp[v1][v2]);
            glomax = max(glomax,dp[v1][v2]);
        }
    }

    for(int i=2;i<=n-1;i++)
    {
        vector<int> come;
        for(int j=0;j<3;j++) come.pb(a[i * 3 + j]);
        int pop_boost = booost;
        int pop_max = glomax;
        // two / zero
        if(come[0] == come[1] && come[1] == come[2])
        {
            booost++;
            glomax++;
        }
        maybe.clear();
        sort(come.begin(),come.end());

        // zero / two

        for(int j=0;j<3;j++)
        {
            for(int k=j+1;k<3;k++)
            {
                int v1 = come[j];
                int v2 = come[k];
                int v3;
                for(int c=0;c<3;c++)
                {
                    if(c != j && c != k) v3 = come[c];
                }
                if(v1 > v2) swap(v1,v2);
                int val = pop_max;
                val = max(val,dp[v3][v3] + 1 + pop_boost);
                maybe.pb(mp(mp(v1,v2), val));
            }
        }
        // one / one

        for(int j=0;j<3;j++)
        {
            vector<int> rest;
            for(int k=0;k<3;k++)
            {
                if(k != j) rest.pb(come[k]);
            }
            for(int k=1;k<=n;k++)
            {
                int v2 = k;
                int v1 = come[j];
                int val = maxi[v2];
                if(v1 > v2) swap(v1,v2);
                if(rest[0] == rest[1])
                {
                    int x = rest[0];
                    int y = k;
                    if(x > y) swap(x,y);
                    val = max(val,dp[x][y] + pop_boost + 1);
                }
                maybe.pb(mp(mp(v1,v2), val));
            }
        }

        if(booost > pop_boost)
        {
            for(int j=1;j<=n;j++) maxi[j]++;
        }

        for(auto x : maybe)
        {
            int v1 = x.st.st;
            int v2 = x.st.nd;
            int val = x.nd;

            if(val > dp[v1][v2] + booost)
            {
                dp[v1][v2] = val - booost;
                maxi[v1] = max(maxi[v1],val);
                maxi[v2] = max(maxi[v2],val);
                glomax = max(glomax,val);
            }

        }

        maybe.clear();
    }

    int ans = glomax;
    int v = a[n * 3];
    ans = max(ans,dp[v][v] + 1 + booost);
    cout<<ans<<endl;

    return 0;
}
