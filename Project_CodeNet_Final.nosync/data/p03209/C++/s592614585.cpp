#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz size
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORRN(i,a,b) for (int i = (a); i >= (b); i--)
#define FORR(i,a,b) for (int i = (a); i > (b); i--)
typedef unsigned long long ull;
typedef long long ll;

ll a[1005],b[1005];

ll check(ll n,ll x){
	if(n==0){
		if(x<=0)
			return 0;
		else
			return 1;
	}else if(x<=1+a[n-1]){
		return check(n-1,x-1);
	}else{
		return b[n-1]+1+check(n-1,x-2-a[n-1]);
	}
}

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

    ll n,x;
    cin >> n >> x;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    a[0]=1,b[0]=1;

    FOR(i,1,n){
    	a[i]=a[i-1]*2+3;
    	b[i]=b[i-1]*2+1;
    }

    cout << check(n,x);

    return 0;
}
