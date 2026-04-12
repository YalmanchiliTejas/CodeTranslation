#include<bits/stdc++.h> 
using namespace std;

int d,mod=1e9+7;
long long dp[10000][101][2];

long long addself(long long a,long long b)
{
    if(a+b >= mod)
        return a+b-mod;
    return a+b;
}

long long multipleofD(int index,int sum,int tight,const vector<int> &a)
{

    if(index==a.size())
        return sum==0;

    if(dp[index][sum][tight]!=-1)
        return dp[index][sum][tight];
        
    int m=tight? a[index] : 9;

    long long ans=0;
    for(int i=0;i<=m;i++)
    {
        int newtight= tight? (i==a[index]): 0;
        ans = addself(ans,multipleofD(index+1,(sum+i)%d,newtight,a));
    }
    return dp[index][sum][tight]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    memset(dp,-1,sizeof(dp));

    string k;
    int i,j;
    cin>>k>>d;
    vector<int> a(k.length());
    for(i=0;i<k.length();i++)
        a[i]=k[i]-'0';
    
    long long res = multipleofD(0,0,1,a);
    
    res-=1;
    if(res<0)
        res+=mod;
    cout<<res<<endl;
}