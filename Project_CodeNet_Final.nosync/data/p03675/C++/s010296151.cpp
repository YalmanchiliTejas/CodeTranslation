#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <cmath>
#include <deque>
#include <bitset>
#define ll long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x);
#define readll(x) cin>>x;
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define MP make_pair
#define PB push_back
#define pii pair<int,int>
#define readN(N,X) for(int i=0;i<N;i++) cin>>X[i];
#define pff pair<double,double>
using namespace std;

int N;
int a[200005];
int ans[500005];
int F = 200000;
int L = 200001;

int main(){
   std::ios::sync_with_stdio(false); 
   cin>>N;
   readN(N,a);
   memset(ans,-1,sizeof(ans));
   bool rev = 0;
   FOR(i,0,N){
   		if (rev) {
   			ans[L++] = a[i];
   		} else {
   			ans[F--] = a[i];
   		}
   		rev = 1 - rev;
   }
   vector<int> res;
   for (int i=F;i<=L;i++)
   	res.push_back(ans[i]);
   if (!rev) reverse(res.begin(), res.end());
   for (int x: res)
   		if (x !=-1)cout<<x<<" ";

}

