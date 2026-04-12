#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL)
#define F(i,b) for(int i= 0; i<(int)(b);i++)
#define FI(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define inp(a) for(auto& i : a) cin >> i;
#define what_is(x) cerr << #x << " is " << x << endl;
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pii pair<int,int>
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007
const int N = 2e5+7 ;
string s ;

int main(){fast ;
	int x,y,z ;
	cin >> x >> y >> z ;
	x = x - (2*z) ;
	int q = x / (y+z) ;
	int rem = x % (y+z) ;
	if(rem >= y)
		q++ ;
	cout << q << endl ;

}