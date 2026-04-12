#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll mod=1e9+7;

    void add_self(int&a,int b)
    {
        a+=b;
        if(a>=mod)
            a-=mod;
        return;
    }

    int main()
    {
        int T=1;
        //cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            string a;
            cin>>a;
            int d;
            cin>>d;
            int len=a.length();
            vector<vector<int>> dp(d,vector<int>(2));
            dp[0][0]=1;
            for(int i=0;i<len;i++)
            {
                vector<vector<int>> new_dp(d,vector<int>(2));
                for(int sum=0;sum<d;sum++)
                {
                    for(bool small:{false,true})
                    {
                        for(int dig=0;dig<10;dig++)
                        {
                            if(dig>(a[i]-'0') && !small)
                                break;
                            add_self(new_dp[(sum+dig)%d][small || dig<(a[i]-'0')],dp[sum][small]);
                        }
                    }
                }
                dp=new_dp;
            }
            int ans=dp[0][0]+dp[0][1]%mod;
            ans--;
            if(ans<0)
                ans+=mod;
            cout<<ans;
        }
        return 0;
    }