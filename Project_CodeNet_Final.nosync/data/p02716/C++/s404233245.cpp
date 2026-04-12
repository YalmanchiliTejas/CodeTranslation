#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mk make_pair
#define pi pair<int, int>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
using namespace std;
int dt[][2]= {{1,0},{-1,0},{0,1},{0,-1},{0,0}};
//typedef pair<int, int> P;
//priority_queue<int, vector<int>, greater<int> > q;

/*
设 dp[i] 为长为 i 时取 ⌊i2⌋ 个数的最大和。

当 i 为奇数时，如果取 ai，dpi=dpi−2+ai，否则 dpi=dpi−1。

当 i 为偶数时，如果取 ai，dpi=dpi−2+ai，否则 dpi=pre_sumi−1。

比如当 i=4 时，如果不取 a4，要想在之前的 a1 a2 a3 中取够 2 个数，

只能取 a1 a3，即从  a1 起间隔为 2 取数作奇数位的前缀和。
*/
const int N=2e5+5;
ll a[N];
ll pre_sum[N]={};
ll dp[N]={};

int main()
{
   IOS;
   int n;
   cin >> n;
   rep(i,1,n) cin >> a[i];
   pre_sum[1]=a[1];
   for(int i=3;i<=n;i+=2) pre_sum[i]=pre_sum[i-2]+a[i];
   rep(i,2,n){
       if(i&1) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
       else dp[i]=max(pre_sum[i-1],dp[i-2]+a[i]);
   }
   cout << dp[n];
}
