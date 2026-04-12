/*------------------------------------ 
........Bismillahir Rahmanir Rahim.... 
..........created by Abdul Aziz....... 
------------------------------------*/ 
#include <iostream> 
#include <algorithm> 
#include <stdio.h> 
#include <cmath> 
#include <vector> 
#include <set> 
#include <list> 
#include <map> 
#include <cstring> 
#include <unordered_map> 
#include <queue> 
#define   mod  998244353 
#define   int  long long 
#define   ld   long double 
#define   pb   push_back 
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   sz(x)  (int)x.size() 
#define   all(a) (a.begin(),a.end()) 
#define   ff   first 
#define   ss   second 
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
	map <int,int> cnt;
    int n,h=-1; cin>>n; 
    vi a(n);
    for (int i=0,j=0;i<n;i++) 
    	cin >> a[i] ; 
    sort(a.begin(),a.end()); 
    vi res(n);
    if (n&1) res.resize(n-1);
    for (int i=0,j=0;i<n;i++){
    	if (n&1 and i==n/2) h=a[i];
    	else res[j++] = a[i];
    }
    if (n&1) n--;
    list <int> r1;
    r1.pb(res[0]);
    for (int c=1,i=1,j=n-1,k=1;k<n;k++,c+=2){
    	if (k&1) {
    		if (!cnt[j]) r1.pb(res[j]);
	    	if (c+1<n) r1.push_front(res[j-1]);
	    	j -= 2; 
	    	cnt[j+1] = cnt[j+2] = 1;
	    }
	    else {
	    	if (!cnt[i]) r1.pb(res[i]);
	    	if (c+1<n) r1.push_front(res[i+1]);
	    	i += 2; 
	    	cnt[i-1] = cnt[i-2] = 1;
	    }
    }
    int ans=0,pre=-1;
    for (auto &it: r1) {
    	if (pre != -1) ans += abs(pre-it);
    	pre = it;
    } 
    int l=r1.front(),r=r1.back();
    if (h != -1) ans += max(abs(l-h),abs(r-h)); 
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*
10
5
6 8 1 2 3

5
1 8 2 6 3

6
1 1 3 4 5 9

5
3 1 3 1 3

3 
1 1 3

3
1 3 3

*/
