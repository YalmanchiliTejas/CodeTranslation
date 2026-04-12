#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    string ans="",s[n+5];
    map<int,int>mp[n+5];
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<s[i].length(); j++)
        {
            mp[i][s[i][j]]++;
        }
    }
    for(int i='a'; i<='z'; i++)
    {
        int mn=INT_MAX;
        for(int j=0; j<n; j++)
            mn=min(mn,mp[j][i]);
        for(int j=0; j<mn; j++)
            ans+=i;

    }
    cout<<ans<<endl;

    return 0;
}
