
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ff         first
#define ss         second
#define endl       '\n'
#define pb         push_back
#define int        long long
#define vi         vector<int>
#define mii        map<int, int>
#define pii        pair<int, int>
#define all(x)     (x).begin(), (x).end()
#define fill(a,b)  memset(a, b, sizeof(a))
#define setbits(x) __builtin_popcountll(x)
#define rep(i,x,y) for(int i=(int)x; i<y; i++)
#define px(a)      for(auto x: a) cout<<x<<" "; cout<<'\n';
#define pxy(a,n)   rep(i,0,n) {px(a[i])};

/*_________________________________________________________*/
const long long MOD=1e9+7,N=1e5+5;
int power(int x, unsigned int y)  
{  
    int res = 1;
    x = x % MOD;
    if (x == 0) return 0;
  
    while (y > 0)  
    { 
        if (y & 1)  
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;  
    }  
    return res;  
}

int solve()
{
	int n,x,m,ans=0;
	cin>>n>>x>>m;
	int a[m]={0},b[m+1]={0};
	int t=x%m, i=1,j=-1;
	for(i=1;i<=n;i++){
		if(a[t]!=0){
			j=a[t];
			break;
		}
		a[t]=i;
		ans+=t;
		b[i]=ans;
		t=(t*t)%m;
	}
	//cout<<i<<" "<<j<<endl;
	ans+=(b[i-1]-b[j-1])*((n-i+1)/(i-j));
	ans+=b[j-1+(n-i+1)%(i-j)]-b[j-1];
	return ans;
}
int32_t main()
{	
	std::ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<solve()<<endl;
}