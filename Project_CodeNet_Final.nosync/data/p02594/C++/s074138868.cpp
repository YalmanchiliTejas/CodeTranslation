#include<bits/stdc++.h>
#include<iostream>
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(v) v.begin(),v.end()
#define BP(n) __builtin_popcount(n)
#define bs(v,x) binary_search(all(v),x)
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(j,n) for (j=i+1;j<n;j++)
#define Unique(v) vector<int>::iterator it; sort(all(v)); it= unique(all(v)); v.resize(distance(v.begin(),it))
#define mod 1000000007
#define PI acos(-1.0)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) 
using namespace std;
/*void input(vector<int>& v,int n){ int i,io; rep(i,n) { cin>>io; v.pb(io);} }
void output(vector<int> v) { int i; rep(i,v.size()) cout<<v.at(i)<<" "; }
map<char,int>  frequency(string v){ int i; map<char,int> m; rep (i,v.length()) {  if (m.find(v[i])==m.end()) m.insert({v.at(i),1}); else m[v.at(i)]++; } return m; }
bool perfsq(ll n){ return (ceil(sqrt(n))==floor(sqrt(n))); }
bool ispower2(int n) { if (n&(n-1)==0) return true; else return false; }
bool binary_pred(int a,int b){ return a==b; }*/
int main() {
	fastio;
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	if (n>=30)
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl;
}

