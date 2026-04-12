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

const int N = 2e5+5;
ll a[N];
ll suf[N];

int main()
{
   IOS;
   int n;
   cin >> n;
   rep(i,1,n)cin >> a[i];
   suf[n+1] = 0;
   suf[n] = a[n];
   per(i,n-1,1)suf[i] = (suf[i+1]+a[i])%mod;
   //rep(i,1,n)cout << suf[i] << endl;
   ll sum = 0;
   rep(i,1,n)
   {
       sum = (sum + a[i]*suf[i+1]%mod)%mod;
   }
   cout << sum;
}
