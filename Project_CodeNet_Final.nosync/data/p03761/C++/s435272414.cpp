#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod = (ll)1e9+7;
const ll INF = (ll)1e18+1;

void add(ll &x, ll y)
{
    x+=y;
    if(x>=mod)
    {
        x-=mod;
    }
}

vector<string> v(51);
vector<int> ar(51);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string ans="";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        sort(v[i].begin(), v[i].end());
    }
    for(int i='a'; i<='z'; i++)
    {
        int mi=51;
        for(int j=0; j<n; j++)
        {
            int c=0;
            while(v[j][ar[j]]==i)
            {
                c++;
                ar[j]++;
                if(ar[j]>v[j].length()) break;
            }
            mi = min(mi, c);
        }
        while(mi--) ans+=i;
    }

    cout << ans;
}

//TODO: 56
//come back to 50D, 55D, DP-J
