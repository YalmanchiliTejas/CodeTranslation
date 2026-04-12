#include<iostream>
#define mod 1000000007
#define lim 2000
using namespace std;
 
unsigned long long store[lim];  //store[i]=i!% mod
 
inline unsigned long long power(int n,unsigned long long k ,int m=1000000007)  //return n^k % m
{
 if(k==0) return 1;
 if(k==1) return n;
 unsigned long long f=power(n,k/2,m);
 unsigned long long p=(f*f)%m;
 if(k%2!=0)
  p=(p*n)%m;
 
 return p;
}
 
 
inline unsigned long long invmod(int n,int m)
{
 return power(n,m-2,m);
}
 
void create_store(int m)
{
 
       store[0]=1;
    for(int i=1;i<lim;i++)
    {
        store[i]=(store[i-1]*i)%m;
    }
 
}
 
inline unsigned long long func(int c,int p)
{
    unsigned long long X=power(store[c],p)*store[p];
    return invmod(X%mod,mod);
}
 
unsigned long long dp[1002][1002];
 
int main()
{
    create_store(mod);
    int n,A,B,C,D;
    cin>>n;
    cin>>A>>B>>C>>D;
    dp[A-1][0]=store[n];
    for(int i=A;i<=B;i++)
    {
        //dp[i][0]=store[n];
        for(int p=0;p<=n;p++)
        {
            dp[i][p]=dp[i-1][p];
            for(int cnt=C;cnt<=D;cnt++)
            {
              //  cout<<i<<" "<<cnt<<"\n";
                if(cnt*i>p)
                    break;
                //cout<<dp[i-1][p-cnt*i]<<"&&"<<func(i,cnt)<<" ^^"<<p-cnt*i<<"\n";
                dp[i][p]+=dp[i-1][p-cnt*i]*func(i,cnt);
                dp[i][p]%=mod;
            }
        }
    }
    cout<<dp[B][n];
    return 0;
}