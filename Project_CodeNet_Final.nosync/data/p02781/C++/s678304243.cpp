#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    string s;
    cin>>s;
    ll n=s.size();
    int k;
    cin>>k;
    if (k==1)
    {
        cout<<9*(n-1)+s[0]-'0';
        return 0;
    }
    if (k==2)
    {
        ll cnt=0;
        int ind=-1;
        for (int i=1;i<n;i++)
        {
            if (s[i]!='0') {
                ind = i + 1;
                break;
            }
        }
        cnt+=9*9*(n-1)*(n-2)/2;
        cnt+=9*(n-1)*(s[0]-'0'-1);
        if (ind!=-1)
        {
            cnt+=(n-ind)*9;
            cnt+=s[ind-1]-'0';
        }

        cout<<cnt;
        return 0;
    }
    if (k==3)
    {
        ll cnt=0;
        int ind=-1,ind1=-1;
        for (int i=1;i<n;i++)
        {
            if (s[i]!='0') {
                ind = i + 1;
                break;
            }
        }
        if (ind!=-1)
        {
            for (int i=ind;i<n;i++)
            {
                if (s[i]!='0')
                {
                    ind1=i+1;
                    break;
                }
            }
        }
        cnt+=(n-1)*(n-2)*(n-3)*9*9*9/6;
        cnt+=(s[0]-'0'-1)*9*9*(n-1)*(n-2)/2;
        if (ind!=-1)
        {
            cnt+=9*9*(n-ind)*(n-ind-1)/2;
            cnt+=(s[ind-1]-'0'-1)*9*(n-ind);
            if (ind1!=-1)
            {
                cnt+=9*(n-ind1);
                cnt+=s[ind1-1]-'0';
            }
        }
        cout<<cnt;
        return 0;
    }







}