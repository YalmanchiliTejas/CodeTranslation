#include<iostream>
#include<iostream>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
#include<cstdio>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define bll __builtin_popcountll
#define bufclr while((getchar())!='\n')
#define bufcl int ws=cin.get()
#define bl "\n"
#define mp make_pair
#define pb push_back
#define ll long long int
#define UI unsigned int
#define mod  1000000007 /*998244353*/ 
//#define fs first
//#define sc second
#define fora(i,a,x) for(int i=a; i<x; ++i)
#define fors(i,x,a) for(int i=x; i>a; --i)
using namespace std;
void op(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}
int C(pair<int,int> &a ,pair<int,int> &b){
	return a.first<b.first;
}
int main() { 
    	op();
			long long  ans=0,sum=0;
		
			long long  n;
			cin>>n;
		for(int i=0; i<n; ++i){
			long long  a;
			cin>>a;
			ans = (ans + (sum*a)%mod)%mod;
			sum= (sum + a)%mod;
		}
		cout<<ans;
		}
		//cout<<ans;





            