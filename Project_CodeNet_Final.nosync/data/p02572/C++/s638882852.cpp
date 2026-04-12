#include<bits/stdc++.h>
#define ull unsigned long long
#define ll int64_t 
#define f(i,s,e) for(i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1) 
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a) emplace_back(a)
#define print(x) for(auto it:x) cout<<it<<' '; cout<<"\n";
#define int long long
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

ll fpower(ll x,ll y)
{
	if(!y)
		return 1;
	return (y&1) ? x*fpower(x*x%mod,y/2)%mod : fpower(x*x%mod,y/2)%mod ;
}

int findProductSum(vector <ll> A, ll n) 
{ 
    int array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = (array_sum + A[i])%mod; 
    int array_sum_square = (array_sum * array_sum)%mod; 
    int individual_square_sum = 0; 
    for (int i = 0; i < n; i++) 
        individual_square_sum = (individual_square_sum + A[i]*A[i])%mod; 
    return ((array_sum_square - individual_square_sum + mod)%mod)*(fpower(2,mod-2)%mod)%mod; 
} 
main()
{
	FAST_IO ;
	ll i,j,k,n;
	cin >> n;
	vector <ll> arr(n);
	for(i=0;i<n;++i)
		cin >> arr[i] ;
	cout << findProductSum(arr,n) endl ;
	return 0;
}
 
/*
If u haven't come up with an approach yet ,skip this one
  Try this when feeling stuck -
  1. Int overflow, array bounds
  2. Special cases (n=1?)
  3. Prove your approach to yourself(mathematical induction,counter-intuitive or stronger test cases)
  4. Calm down and don't look at standings and stop thinking about rating and think about the question
  5. Just do it! 
*/ 

//Benq's advice - 
/* 
	And following advices are must for me -
	* do something instead of nothing and stay organized
	* WRITE STUFF DOWN 
*/

//#define _GLIBCXX_DEBUG 
// It will convert WA verdict to runtime error if that error is caused due to out of bound excess , declare it at the top
//#pragma GCC optimize "trapv" 
// It will convert WA to runtime error if WA was caused due to int overflow error,declare it anywhere