#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

void add_self(int &a,int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int len=s.size();

    int d;
    cin >> d;
    vector <vector<int> > dp(d,vector <int>(2));
    dp[0][0]=1;

    for (int i=0;i<len;i++)
    {
        vector <vector <int> > new_dp (d,vector <int> (2));
        for (int sum=0;sum<d;sum++)
            for (bool sth:{false , true})
                for (int digit=0;digit < 10;digit++)
        {
            if (digit>s[i]-'0' && !sth)
                break;

            add_self(new_dp[(sum+digit)%d][sth || digit<s[i]-'0'],dp[sum][sth]);
        }

        dp=new_dp;
    }

    int answer=(dp[0][0]+dp[0][1])%mod;
    answer--;
    if (answer==-1)
        answer=mod-1;
    cout << answer;

}

