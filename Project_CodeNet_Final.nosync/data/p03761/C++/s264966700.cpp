//bad_bat
#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define mod 1000000007

int main()
{

    int n;
    cin >> n;
    int ara[n][26];
    mset(ara,0);
    for(int i=0; i < n; i++)
    {

        string ss;
        cin >> ss;
        for(int j=0; j < ss.size(); j++)
        {

            int x = ss[j] - 'a';
            ara[i][x]++;
        }
    }
    int ans[26];
    mset(ans,0);
    for(int i=0; i < 26; i++)
    {

        int x = 1e9;
        for(int j=0; j < n; j++) x = min(x, ara[j][i]);
        ans[i]=x;
    }
    string ret;
    for(int i=0; i < 26; i++)
    {

        char c = 'a'+i;
        for(int j=0; j < ans[i]; j++) ret.pb(c);
    }
    cout << ret;
}
