#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef map<ll,ll> mpll;
typedef set<ll> setll;
typedef multiset<ll> msetll;

#define F first
#define S second
#define pb push_back
#define mp make_pair

const ll mod = 1e9 + 7;

ll d,n;
vector<ll> v;
ll memo[10001][101][2];

ll func(ll i,int rem,int tt){
	if(i==n-1){
		ll temp = v[i];
		if(tt==1)
			temp=9;
		ll cnt =0;
		while(temp>=0)
		{
			if((temp+rem) % d == 0)
				cnt++;
			temp--;
		}
		return cnt;
	}
	if(memo[i][rem][tt]!=-1)
		return memo[i][rem][tt];
	ll temp = v[i];
	if(tt==1)
		temp=9;
	ll cnt = 0;
	if(tt==1)
	{
	while(temp>=0)
	{
		
		cnt+=func(i+1,(temp+rem)%d,tt);
		//cout<<temp<<" "<<cnt<<"\n";
		cnt = cnt%mod;
		temp--;
	}
	}
	else{
		cnt+=func(i+1,(temp+rem)%d,0);
		//cout<<temp<<" "<<cnt<<"\n";
		cnt = cnt%mod;
		temp--;
		while(temp>=0)
		{
		
			cnt+=func(i+1,(temp+rem)%d,1);
			//cout<<temp<<" "<<cnt<<"\n";
			cnt = cnt%mod;
			temp--;
		}
	}
	return memo[i][rem][tt]=cnt;
}

int main()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifdef DEBUG_
		freopen("input.txt","r",stdin);
	#endif
	cout.setf(ios::fixed), cout.precision(20);

	string k;
	cin >> k ;
	cin >> d ;

	for(int i=0;i<(int)k.size();i++){
		v.push_back((int)(k[i]-'0'));
	}
	n = k.size();
	for(int i=0;i<10001;i++){
		for(int j=0;j<101;j++){
			memo[i][j][0]=-1;
			memo[i][j][1]=-1;
		}
	}
	cout<<(func(0,0,0)- 1 + mod)%mod<<"\n";

	return 0;
}