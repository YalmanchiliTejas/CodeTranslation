#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int N,A,B,C,D;
long long fa[1001];
long long modinv(long long a, long long m);
long long power(long long b, long long p);
void setting(int n);
unsigned long long groupsplit(int n,int r,int m);


int main()
{
    cin >> N >> A >> B >> C >> D;
    vector <vector <long long>> dp(B-A+2,vector <long long> (N+1));
    for (int i=0;i<B-A+2;i++)
    {
        for (int j=0;j<N+1;j++)
        {
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    setting(1000);
    for (int i=1;i<B-A+2;i++)
    {
        for (int j=0;j<N+1;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                for(int group=C;group<min(D+1,j/(A+i-1)+1);group++)
                {
                  dp[i][j]=(dp[i][j]+dp[i-1][j-(A+i-1)*group]*groupsplit(N-j+(A+i-1)*group,A+i-1,group))%mod;
                }
        }
    }
    cout << dp[B-A+1][N] << endl;
return 0;
}

long long modinv(long long a, long long m) 
{
    return power(a,m-2)%mod;
}

long long power(long long b, long long p)
{
    long long res = 1, a = b;
    for(; p; p >>= 1){
      if(p&1) res = res * a % mod;
      a = a * a % mod;
    }
    return res;
}

void setting(int n)
{
  fa[0]=1;
  for (int i=1;i<n+1;i++) fa[i]=i*fa[i-1]%mod;
  return;
}

unsigned long long groupsplit(int n,int r,int m)
{
  unsigned long long s;
  s=fa[n];
  s=s*modinv(fa[n-r*m],mod)%mod;
  s=s*modinv(power(fa[r],m),mod)%mod;
  return s*modinv(fa[m],mod)%mod;
}