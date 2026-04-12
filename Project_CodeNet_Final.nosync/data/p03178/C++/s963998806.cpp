#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second

ll inf =1e16+10;
const int N=1e4+5, S = 102, D = 11, mod = 1e9+7;
int n, DIV;
int a[N];
string s;
int mem[N][S][3];

int dp(int i, int sum, bool f)
{
    if (i == n)
        return  f&&(sum%DIV == 0);

    int &ret = mem[i][sum%DIV][f];
    int leng = 0;

    if (ret != -1)
      return ret;
   // cout<<i-1<<" "<<sum<<" "<<dig <<"  "<<f<<"\n";
    for (int j = 0; j<=9; j++)
    {
        leng += dp(i+1, sum+j, j<a[i] || (j == a[i] && f));
        leng %= mod;

    }
    return  ret = leng;
}

int main()
{
#ifdef Mohammad
    freopen("input.in","r",stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >>DIV;
    n = s.size();
    reverse(s.begin() , s.end());
    for (int i =0; i<s.size() ; i++)
        a[i] = s[i]-'0';

    memset(mem, -1, sizeof mem);
    // for (int i = 0 ;i<=a[0];i++)
    cout<<(((dp(0, 0, 1)-1)%mod + mod ) %mod);
//    cout<<ans;
}
