#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
ll gcd(ll x, ll y)
{                     
        return (x==0)? y : gcd(y % x, x);
}

int main(){
    int x ; cin >> x ;
    if( x == 7 || x == 5 || x == 3){
    	cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}