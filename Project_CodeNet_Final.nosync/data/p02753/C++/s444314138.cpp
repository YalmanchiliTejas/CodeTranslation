#include <bits/stdc++.h>
 
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define stk stack<int>
#define que queue<int>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mod=1e9+7;

using namespace std;

int main(){
	string s;
	cin>>s;
	set<char> se(s.begin(), s.end());
	if(se.size()==1)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}