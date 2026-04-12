//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll
int p[212345];
vector<vi> facto(123456),sum1(123456),sum2(123456);

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>p[i];
    }
    int sz,j;
    for(i=1;i<123456;i++){
    	sum1[i].pb(0);
    	sum2[i].pb(0);
    	for(j=i;j<123456;j+=i){
    		facto[j].pb(i);
    		sz=sum1[i].size();
    		if(j<=n-1)
    			sum1[i].pb(sum1[i][sz-1]+p[j]);
    		sz=sum2[i].size();
    		if(n-1-j>=0)
    			sum2[i].pb(sum2[i][sz-1]+p[n-1-j]);
    	}
    }
    //return 0;
    int ans=0,req,a,b,ab,gg,h;
    f(i,1,n-1){
    	a=i;
    	req=n-1-a;
    	rep(j,facto[req].size()){
    		if(facto[req][j]>=a)
    			break;
    		b=a-facto[req][j];
    		ab=a-b;
    		h=req/ab;
    		if(a%ab==0 && a/ab<=h)
    			continue;
    		//cout<<a<<" "<<b<<endl;
    		gg=sum1[ab][h];
    		gg+=sum2[ab][h];
    		ans=max(ans,gg);
    	}
    }
    cout<<ans<<endl;
    return 0;   
}
