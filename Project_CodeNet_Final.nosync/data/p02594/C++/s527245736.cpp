#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); it++)
#define vi vector<int>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define nth(v,n) nth_element(v.begin,v.begin+n-1,v.end())
#define dnth(v,n) nth_element(v.begin,v.begin+n-1,v.end(), greater<int>())
#define pb push_back
#define ll long long

int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
}
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
}
int cel(int a,int b){return((a-1)/b+1);} 
int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void dfs(int u,vi &visited,vi adj[]) {
    visited[u] = 1; 
	for (int i=0; i<adj[u].size(); i++) 
		if (visited[adj[u][i]] == 0) 
			dfs(adj[u][i],visited,adj); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n;
    if(n>=30)cout<<"Yes";
    else cout<<"No";
    return 0;
}