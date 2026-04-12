#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define takeline cin.ignore();
#define iactive cout.flush();
#define N 200005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
string s; vector<ll> vc; ll k; ll dp[101][3][101];
ll findans(ll pos,ll flg,ll cnt){
//	cout<<pos<<" "<<cnt<<endl;
	if(pos==vc.size()){
		if(cnt==k)
			return 1;
		else return 0;
	}
	if(dp[pos][flg][cnt]!=-1){
		return dp[pos][flg][cnt];
	}

	ll an=0,lmt;
	if(flg==0){
		lmt=vc[pos];
	}
	else {
		lmt=9;
	}
	//cout<<pos<<" "<<lmt<<endl;
	for(ll i=0;i<=lmt;i++){
		ll nf=flg,c=cnt;
		if(flg==0&&i<lmt) nf=1;
		if(i!=0) c++;
		an+=findans(pos+1,nf,c);
	}
	return dp[pos][flg][cnt]=an;
}
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,l,n;
	cin>>s;
	n=s.length();
	cin>>k;
	for(i=0;i<n;i++){
		vc.ps(s[i]-'0');
	}
	memset(dp,-1,sizeof(dp));
	ll an=findans(0,0,0);
	cout<<an;
	return 0;
}