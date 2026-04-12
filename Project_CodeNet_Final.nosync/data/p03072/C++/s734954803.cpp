/*
*  Author: windystreet
*  Date  : 2019-04-13 20:02:03
*  Motto : Think twice, code once.
*/
#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define eps  1e-5
#define gcd __gcd
#define pb push_back
#define PI acos(-1.0)
#define lowbit(x) (x)&(-x)
#define bug printf("!!!!!\n");
#define mem(x,y) memset(x,y,sizeof(x))

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef unsigned long long uLL;

const int maxn = 100+7;
const int INF  = 1<<30;
const int mod  = 1e9+7;

int s[maxn];
int a[maxn];
void solve(){
    int n;
    while(cin>>n){
    	s[0] = 0;
    	mem(a,0);
    	int ans= 0;
    	for(int i=1;i<=n;i++){
    		cin>>s[i];
    		a[i] = max(a[i-1],s[i]);
    	}
    	for(int i=1;i<=n;i++){
    		if(a[i] == s[i]) ++ans;
    	}
    	cout<<ans<<'\n';
    }
    
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("F:/in.txt","r",stdin);
#endif
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false);
    int t = 1;
    //scanf("%d",&t);
    while(t--){
    //    printf("Case %d: ",cas++);
        solve();
    }
    return 0;
}