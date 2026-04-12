#include<iostream>
#define ll int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	if(n>=30)
		cout<<"Yes";
	else
		cout<<"No";
}