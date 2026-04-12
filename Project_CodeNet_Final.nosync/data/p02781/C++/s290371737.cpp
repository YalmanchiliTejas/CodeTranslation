#include <bits/stdc++.h>
#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define PER(I, A, B) for (int I = (A); I >= (B); --I)
#define lson k*2
#define rson k*2+1
#define fi first
#define se second
#define DB(A) cout<<(A)<<endl
#define DB1(A,B,C) cout<<(A)<<" "<<(B)<<" "<<(C)<<"!"<<endl
#define PB push_back
#define Pair pair<int,int>
#define MP make_pair
#define LL long long
#define int LL
using namespace std;
const int maxn=100+10;
const int MAX=100;
const int inf=0x3f3f3f3f;   
const int mod=1e9+7;
//head
int n,m;
int dp[maxn][MAX];
int digit[maxn];
//dfs:第k位（从高位到低位），limit==1表示第k+1位达到上限（若k为最高位，limit也为0（因为第tot位已达到上限0））， lead==0表示有前导0 
int dfs(int k,bool limit,bool lead,int num) //num表示已经有多少个non-zero digits 
{
	if (k==0&&num==n) return 1;
	else if (k==0) return 0;
	if (!limit&&lead&&(dp[k][num]!=-1)) return dp[k][num];
	//limit为0，表示没有达到上限， lead为1，前面那个不是前导0，dp！=-1，说明已经遍历过。返回这个枚举到第k位，且上一位是last的状态 
	int upbound=(limit?digit[k]:9);//limit为1，有限制，返回这个限制，否则返回9 
	int ans=0;
	FOR(i,0,upbound)
	{		
		if (i==0)
		{
			ans+=dfs(k-1,limit&&(i==upbound),(!((lead==0)&&(i==0))),num);	
		} 
		else
		{
			ans+=dfs(k-1,limit&&(i==upbound),(!((lead==0)&&(i==0))),num+1);
		}		
		//limit&&(i==upbound)，若前面封顶了且这个i也封顶了，那么从最高位到这一位都封顶了，limit保持1		
		//(!lead)&&(i==0)仅当上一位是前导0且这一位还是0时lead才继续保持0 
		//前导0影响0的统计
	}
	if (!limit&&lead) dp[k][num]=ans;
	return ans;
}
int solve(string s)
{
	memset(dp,-1,sizeof(dp));
    int len=s.size();
    int tot=0;
    PER(i,len,1)
    {
    	digit[++tot]=(int)s[i-1]-48;
	}
    return dfs(tot,1,0,0);    
}
signed main()
{
    string s;
    getline(cin,s);
    scanf("%lld",&n);
    {
		printf("%lld\n",solve(s));	        
    }
}