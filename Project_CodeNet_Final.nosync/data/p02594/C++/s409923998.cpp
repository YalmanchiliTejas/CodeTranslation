// $%U%$
// Mere bas ka nahi hai
// still i'm trying
// apna time aayega
//
//        .--------------.  
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |  
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'                          		  
//
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
#define Test int t;cin>>t;while(t--)
#define endl '\n'
void solve()
{
	int n;
	cin >> n;
	if(n>=30)
	cout << "Yes" << endl;
	else
	cout << "No" << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Test
	solve();
	return 0;
}
