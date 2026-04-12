// select maximum alphabetically character in each iteration 
// KOI NI YAAR SAB SAHI HOEGA  BAS  CHORRO MAT
// ENJOR KARO YAAR
// HAAR MAT MAANO
// // APNA TIME AAYEGA
// BEILIEVE IN GOD
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define loop(i,a,b) for(lli i=a;i<b;i++)
#define loopb(i,a,b) for (lli i=a;i>=b;i--)
#define pb push_back
#define mod 1000000007
#define fast() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) (__gcd((a),(b)))
#define lcm(a,b)(((a)*(b))/gcd((a),(b)))
#define ma 1e18
#define bc __builtin_popcountll
#define vi vector<lli>
#define pr pair<lli,lli>
#define vp vector<pr>
#define F  first
#define S   second
#define lld long double
lli dp[3001][3001][2];
lli a[3009];

lli solve(lli start,lli end , lli prev)
{if(start>end)
{return 0;
}
if(dp[start][end][prev]!=-1)
{return dp[start][end][prev];
}
if(prev==1)
{return dp[start][end][prev]=max(a[start]+solve(start+1,end,0) , a[end]+solve(start,end-1,0));
}
else
{return dp[start][end][prev]=min(solve(start+1,end,1),solve(start,end-1,1));
}
}


int main()
{lli n,sum,x,y;
sum=0;
cin>>n;
loop(i,0,n)
{cin>>a[i];
sum+=a[i];
}
loop(i,0,n)
{loop(j,0,n)
{loop(k,0,2)
{dp[i][j][k]=-1;
}
}
}

x=solve(0,n-1,1);
y=sum-x;
cout<<x-y<<"\n";
}

