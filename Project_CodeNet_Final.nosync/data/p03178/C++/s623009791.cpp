/*       _________
        /|______/ \
        ||  _|_|\  |
        || |_|   | /
        ||    _ / |
        ||  _| \\  \    
        ||_|_|\ || |
        |/_|/ | /|_/
              /__/      Written by: Rishabh Roshan
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int            	long long
#define tree 			ped
#define integer        	int32_t
#define mod         	1000000007
#define vint        	vector<int>
#define pint        	pair<int, int>
#define umint        	unordered_map<int, int>
#define mint        	map<integer, integer>
#define in(x)        	int x; cin>>x
#define setbits(x)    	__builtin_popcountll(x)
#define zerobits(x)    	__builtin_ctzll(x)
#define w(x)        	int x; cin>>x; while(x--)
#define sp(x, y)    	fixed<<setprecision(y)<<x
#define poll(x)        	x.front(); x.pop()
#define f(x)        	for(int i=0; i<x; i++)
#define fj(x)			for(int j=0; j<x; j++)
#define fn(n, x)		for(int i=n; i<x; i++)
#define endl         	'\n'
#define inf         	1e9 
#define order_set     	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

// #include "functions.h"

void om_shree_ganeshaya_namah(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

string s;
int d;
unordered_map<bool, unordered_map<int, umint>> dict;

int calculate(int sum, int index, bool e){

	if(s.length()==index){
		if(sum==0)
			return 1;
		return 0;
	}

	if(dict.find(e)!=dict.end())
		if(dict[e].find(index)!=dict[e].end())
			if(dict[e][index].find(sum)!=dict[e][index].end())
				return dict[e][index][sum];

	int ans=0;
	f(10){
		int a = s[index]-'0';
		if(a==i && e){
			ans+=calculate((sum+i)%d, index+1, true);
			ans%=mod;
			break;
		}
		ans+=calculate((sum+i)%d, index+1, false);
		ans%=mod;
	}
	dict[e][index][sum]=ans;
	return ans;
}

int32_t main() {

    om_shree_ganeshaya_namah();

    cin>>s>>d;

    int ans = calculate(0, 0, true);
    ans--;
    if(ans<0)
    	ans+=mod;
    cout<<(ans);
}