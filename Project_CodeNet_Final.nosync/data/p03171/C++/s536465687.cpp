/*
    author : Divyansh Gupta
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>

using namespace std;

void print_err() {
	cerr<<"\n";
}

template <class T,class... Arg>
void print_err(T x,Arg&&... args) {
	cerr<<x<<" ";
	print_err(args...);
}

#ifdef local
#define debug(...) print_err(__VA_ARGS__)
#else
#define debug(...)
#endif

#define test_case int test_cases;\
                cin>>test_cases;\
                while(test_cases--)
#define lu(var,l,r) for(var=l;var<r;var++)
#define ld(var,r,l) for(var=r;var>=l;var--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>                	
#define br cout<<"\n"
#define sp cout<<" "
#define pr cout<<
#define in cin>>
#define f first
#define s second                    
#define mod 1000000007
            
ll who_will_win(vector<ll> &A,vector<vector<ll> > &dp,vector<vector<bool> > &visited,int l,int r) {
	if(l == r) {
		dp[l][l] = A[l];
		visited[l][l] = true;
		return dp[l][l];
	}
	if(visited[l][r]) 
		return dp[l][r];
	visited[l][r] = true;
	return dp[l][r] = max(
			A[l] - who_will_win(A,dp,visited,l+1,r),
			A[r] - who_will_win(A,dp,visited,l,r-1)
		);
}

void solve(){
	int n,i;
	ll x;
	vector<ll> A;
	vector<vector<ll> > dp(3001,vector<ll>(3001,0));
	vector<vector<bool> > dp_visited(3001,vector<bool>(3001,false));
	in n;
	lu(i,0,n) {
		in x;
		A.pb(x);
	}
	pr who_will_win(A,dp,dp_visited,0,n-1);
	br;
}

int main(){
    // test_case
    solve();
    return 0;
}