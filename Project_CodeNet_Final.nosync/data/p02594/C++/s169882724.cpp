#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define re(n) cin >> n
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define ff(i,x,n) for(ll i=(int)x;i<(int)n;i++)
#define f(i,n) ff(i,0,n)
#define fast std::ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define te(t) ll t; re(t); while(t--)
#define MOD 1000000007

int main(){
	ll x;
	re(x);
	if(x>=30){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	return 0;
}
