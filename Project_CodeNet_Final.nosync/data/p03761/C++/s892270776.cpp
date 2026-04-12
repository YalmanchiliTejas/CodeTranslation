#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define ll  long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << endl;
#define mod 1000000007
// #define max INT_MAX
int main()
{
    int n;string str;
    cin >> n;
    cin >> str;
    int dp[26]={0};
    for(int i=0;i<str.size();i++)
    dp[str[i]-'a']++;
    int temp[26]={0};
    for(int i=1;i<n;i++)
    {
        cin >> str;
        for(int i=0;i<str.size();i++)
        {
            temp[str[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            dp[i] = min(dp[i],temp[i]);
            temp[i]=0;
        }
    }
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<dp[i];j++)
        {
            char ch = i+'a';
            cout << ch ;
            
        }
    }
}