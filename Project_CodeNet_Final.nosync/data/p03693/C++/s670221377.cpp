#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
int main(){
	fast;
	int a,b,c;
	cin>>a>>b>>c;
	if(!((a*100+b*10+c)%4))
		cout<<"YES";
	else
		cout<<"NO";
	
	return 0;
}

