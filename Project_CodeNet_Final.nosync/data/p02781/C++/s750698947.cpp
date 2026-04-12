#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define foo(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define deb(x) cout << #x << "-->" << x << endl;
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        cout << it << " ";        \
    }                             \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
    #define mod 998244353
 
#define fi first
#define se second
int fun(int n,int i){
    if(i==0)
        return 0;
    if(i==1)
        return n;
    else if(i==2)
        return (n * (n - 1)) / 2;
    else if(i==3)
    {
        return (n * (n - 1) * (n - 2)) / 6;
    }
    
}
int power(int i,int j){
    int ans = 1;
    while(j--)
        ans *= i;
    return ans;
}
int solve(string s,int n){
    
    if(s.size()<n)
        return 0;
    if(s.size()==0)
        return 0;
    if(s[0]=='0')
    {
       
        return solve(s.substr(1, s.size() - 1), n );
    }
    if (n == 1)
        return ((s.size()-1)*9+(s[0]-'0'));
    int nn = s.size();
    int ans = 0;
    if((nn-1)>=n)
        ans +=( fun(nn - 1, n)*power(9,n));
    ans += ((s[0] - '0'-1) * fun(nn - 1, n - 1) * power(9, n - 1));
    return ans + solve(s.substr(1, nn - 1), n - 1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << solve(s, n)<<endl;
   
}