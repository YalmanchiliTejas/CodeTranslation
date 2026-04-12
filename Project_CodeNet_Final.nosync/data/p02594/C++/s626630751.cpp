#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define deb(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;

typedef long long int ll;
typedef string str;

ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}

void fast(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main ()
{
	ll t,n,m,k,i,a,b,j;
	cin >> n;
	if(n>=30)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}