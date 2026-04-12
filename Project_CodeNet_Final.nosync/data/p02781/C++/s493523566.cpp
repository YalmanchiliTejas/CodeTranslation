#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
int d[MAXN];
int nbdig;
ll dp[101][5][3];

ll solve(int i,int cnt,int exact,int zeros,bool ok)
{
    
    if(cnt < 0)
        return 0;
    if(i == nbdig)
         return (cnt == 0);
   ll &ret = dp[i][cnt][exact];
    if(ret != -1)
        return ret;
    int st = 0;
     if(zeros != 0)
         ok = 1;
  
     ret = 0;
       // cout << i << ' ' << cnt << ' ' << exact << ' ' << zeros << ' ' << ok << ' ' << st << '\n';
    if(exact)
    {
       ret+=solve(i + 1 , cnt - (d[i] != 0) , 1, d[i], ok);
        for(int j = 0 ; j < d[i] ; j++)
            ret+=solve(i + 1 , cnt - (j != 0) , 0 , j , (ok || j));

    }
    else
    {
         for(int j = 0 ; j <= 9 ; j++)
          ret+=solve(i + 1 , cnt - (j != 0) , 0 , j , (ok or j));
    }
    
    return ret;
}



ll get(string s,int k)
{
    nbdig = (int)s.size();
    for(int i = 0  ; i < nbdig ; i++)
    {
        d[i] = s[i] - '0';
    }
    
    return solve(0,k,1,0,0);
}

int main()
{

string s;
cin >> s;
int k;
cin >> k;
memset(dp,-1,sizeof(dp));
cout << get(s,k);
    
}