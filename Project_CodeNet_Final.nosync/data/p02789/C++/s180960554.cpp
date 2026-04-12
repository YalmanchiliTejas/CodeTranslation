#include<bits/stdc++.h>

#define 	pi 				3.1415926536
#define 	mod 			1000000007
#define 	lli 			long long int
#define 	rep(i, n) 		for(int i = 0 ; i < n ; i++)
#define 	repn(i, n) 		for(int i = n - 1 ; i >= 0 ; i--)
#define 	loop(i, a, b)	for(int i = a ; i < b ; i++)
#define 	mod1 			1000003
#define 	hello 			"hello"
#define 	nl 				"\n"
#define 	ws 				" "
#define 	F 				first
#define 	S 				second
#define 	pb 				push_back
#define 	mp				make_pair
#define 	B 				begin()
#define 	E 				end()
#define 	all(v) 			v.begin(), v.end()
#define 	reset(a, val) 	memset(a, val, sizeof(a))
#define 	vi 				vector<int>
#define 	vs 				vector<string>
#define 	print(a) 		for(auto i : a)cout<<i<<" ";cout<<"\n"
#define 	boost 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

//g++ -std=c++14
//fixed<<setprecision(9);
//max_element(mp.begin(), mp.end(), compare)


bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; }

bool compare(const pair<string, int> &a, const pair<string, int> &b){ return a.second < b.second; }

int gcd(int a, int b) 
{ 	
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

int main()
{
	boost;
	int  n, m;
	cin>>n>>m;
	if(n==m)
		cout<<"Yes"<<nl;
	else
		cout<<"No"<<nl;

}