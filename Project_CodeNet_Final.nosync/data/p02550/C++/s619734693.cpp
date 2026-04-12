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

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

void brute(ll n,ll x,ll m)
{
    ll i,j ;
    ll ans = x ;
	for(i=2;i<=n;++i)
	{
	    j = (x*x)%m ;
	    if(!j)
	        break ;
	    x = j ;
	    ans = ans + j ;
	}
	cout << ans endl ;
}

int main()
{
	FAST_IO ;
	ll i,j,k,n,m,x;
	cin >> n >> x >> m;
	if(n<=1000000)
	{
	    brute(n,x,m) ;
	    return 0 ;
	}
	set < pair<ll,ll> > ms;
	vector <ll> arr ;
	ms.insert({x,1}) ;
	arr.pb(x) ;
	for(i=2;i<=n;++i)
	{
	    j = (x*x)%m ;
	    auto it = ms.lower_bound({j,-1}) ;
	    if(it!=ms.end())
	    {
	        if((*it).F == j)
	        {
	            i = (*it).S ;
	            break ;
	        }
	    }
	    x = j;
	    arr.pb(x) ;
	    ms.insert({x,i}) ;
	}
	ll temp = i ;
	ll sum1 = 0,sum2 = 0,sum3 = 0;
	ll x1 = (ms.size()) - i + 1;
	j = (n-(temp-1))/x1 ;
	k = (n-(temp-1))%x1 ;
	for(i=0;i<temp-1;++i)
		sum3 += arr[i] ;
	for(i=temp-1;i<arr.size();++i)
	    sum1 += arr[i] ;
	 i = temp - 1;
	while(k--)
	{
	    sum2 += arr[i++] ;
	}
	cout << j*sum1 + sum2 + sum3 endl ;
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