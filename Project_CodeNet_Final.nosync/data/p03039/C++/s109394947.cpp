/* Akshat Sharma @akshat98 */
#include <iostream>
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp   make_pair
#define pb   push_back
#define F    first
#define S    second
#define ll   long long
#define MOD  1000000007
#define MAX  1000000001
#define vi 	 vector<int>
#define vl   vector<ll>
#define vpi  vector<pair<int,int> >
#define vpl  vector<pair<ll,ll> >
#define rep(i,a,b) for(i=a;i<b;i++)
#define reqp(i,a,b) for(i=a;i<=b;i++)
#define ren for(i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

ll fact[1000005]={0};

ll mod(ll a,ll m=MOD){
        a%=m;
        if(a<0)a+=m;
        return a;
}

ll sum_of_first_n(ll a){
	ll ans=0;
	ans=1ll*(a)*(a+1)/2;
	return mod(ans);
}

ll power(ll a,ll b,ll m=MOD){
        ll res=1;
        while(b){
                if(b%2)res=mod(1ll*res*a),b--;
                else a=mod(1ll*a*a),b/=2;
        }
        return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen("input_file.txt", "r", stdin);
	//freopen("output_file.txt", "w", stdout);
	#endif
	ll i,j,k,l,n,test_case,m,r;
	test_case=1;
	//cin>>test_case;

	fact[0]=fact[1]=1;
	rep(i,2,1000005){
		fact[i]=mod(i*fact[i-1]);
	}


	while(test_case--){
		cin>>n>>m>>k;
		ll ans=0;
		ll can;
		reqp(i,1,n){
			ll temp=mod(1ll*m*m);
			ll t1=0;
			ll t2;
			// t1=sum_of_first_n(i-1);
			// t1=mod(1ll*t1*temp);
			t2=sum_of_first_n(n-i);
			t2=mod(1ll*t2*temp);
			ans=mod(ans+mod(t1+t2));
			// cout<<(t1+t2)<<".\n";
		}
		// cout<<ans<<"\n";
		reqp(i,1,m){
			ll temp=mod(1ll*n*n);
			ll t1=0;
			ll t2;
			// t1=sum_of_first_n(i-1);
			// t1=mod(1ll*t1*temp);
			t2=sum_of_first_n(m-i);
			t2=mod(1ll*t2*temp);
			ans=mod(ans+mod(t1+t2));
		}

		// cout<<ans<<"\n";
			ll temp;
			temp=fact[n*m-2];
			ll inv_t=power(fact[k-2],MOD-2);

			ll inv_t2=power(fact[n*m-2-(k-2)],MOD-2);
			ll temp2=mod(1ll*inv_t*temp);
			temp2=mod(1ll*temp2*inv_t2);
			cout<<mod(1ll*ans*temp2);


	}
	
	return 0;
}