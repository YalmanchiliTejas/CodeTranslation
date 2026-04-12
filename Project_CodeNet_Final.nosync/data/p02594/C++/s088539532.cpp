#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll int gcd(ll int a, ll int b) {
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}


ll int lcm(ll int x, ll int y){
	return (x*y)/gcd(x,y);
}

int main(){
	int x;
	cin>>x;
	if(x >= 30)
		cout<<"Yes";
	else
		cout<<"No";
}