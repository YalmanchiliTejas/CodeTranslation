#include"bits/stdc++.h"
using namespace std;

/**
 * Copyright (c)
 * author        :   Sujeet Kumar 
 * question name :   
 * link          :   
 */



#define ull long long
#define ll unsigned long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define repA(i,v) for(auto i:v)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define vi vector<int>
#define vll vector<ll>
#define vi2(n,m) vector<vector<int> > v(n,vector<int>(m));

ll modulo = 1e9+7;
ll findProductSum(vector<ll>&v, ll n){
	// cout<<modulo<<endl;
    ll sum = 0; 
    for (ll i = 0; i < n; i++) 
        sum = ((sum%modulo) + (v[i]%modulo))%modulo; 
    sum = sum%modulo;
    ll squareSum = ((sum % modulo)*(sum%modulo))%modulo; 
    squareSum = squareSum % modulo;
    ll newSum = 0; 
    for (ll i = 0; i < n; i++) 
        newSum += ((v[i]%modulo)*(v[i]%modulo))%modulo; 
    newSum = newSum % modulo;
    return ((squareSum - newSum+modulo)*500000004)%modulo;
} 

void solve(){
	ll n;cin>>n;
	vll v(n);
	rep(i,0,n)	cin>>v[i];
	// rep(i,0,n)	cout<<v[i]<<' ';
	// cout<<endl;
	cout<<findProductSum(v,n);
	// cout<<modulo;
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    clock_t start=clock();

	ll test = 1;
	// cin>>test;
	while(test--)	solve();

	clock_t end=clock();
	cerr<<fixed<<setprecision(15)<<((double)(end-start))/CLOCKS_PER_SEC<<endl;
	return 0;
}
/**
 * Test Cases:-
 */
