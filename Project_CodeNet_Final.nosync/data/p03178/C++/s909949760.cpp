#include<bits/stdc++.h>
using namespace std;

typedef long long int in;

in dp[10005][105],cp[10005][105];

in sum(in val)
{
    in ans=0;
    
    while(val)
    {
        ans+=(val%10);
        val=val/10;
    }
    
    return ans;
}

int main() 
{
    string s;
    cin>>s;
    
    in sub=0,d,i,j,k,n=s.size(),l=1000000007,ans=0;
    cin>>d;

    for(i=0;i<10;++i)
    ++cp[1][(sum(i)%d)];
    
    for(i=0;i<100;++i)
    ++cp[2][(sum(i)%d)];
    
    for(i=3;i<=10001;++i)
    {
        for(k=0;k<d;++k)
        {
            for(j=0;j<10;++j)
            {
                cp[i][k]=(cp[i][k]+cp[i-1][((((k-j)%d)+d)%d)])%l;
            }
        }
    
    }
    
    // for(i=0;i<100;++i)
    // cout<<cp[1][(i%d)]<<" ";
    // cout<<"\n";
    
    // for(i=0;i<100;++i)
    // cout<<cp[2][(i%d)]<<" ";
    // cout<<"\n";
    
    // for(i=0;i<100;++i)
    // cout<<cp[3][(i%d)]<<" ";
    // cout<<"\n";
    
    for(i=0;i<n-1;++i)
    {
        for(k=0;k<d;++k)
        {
            for(j=0;j<(s[i]-'0');++j)
            {
                dp[i][k]=(dp[i][k]+cp[n-i-1][(((k-j-sub)%d+d)%d)])%l;
            }
        }
        
        sub=sub+(s[i]-'0');
    }

    for(j=0;j<=(s[n-1]-'0');++j)
    dp[n-1][((((d-j-sub)%d)+d)%d)]=(dp[n-1][((((d-j-sub)%d)+d)%d)]+1)%l;
    
    for(i=0;i<n;++i)
    {
        ans=(ans+dp[i][0])%l;
    }
    
    ans=(ans-1+l)%l;
    
    cout<<ans;
	
	return 0;
}
