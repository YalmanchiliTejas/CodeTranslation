#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

#define ll long long
#define ldb long double
#define db double
#define str string

#define fr first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair

#define pi pair<int,int>
#define pll pair<ll,ll>
#define pdb pair<db,db>
#define pldb pair<ldb,ldb>

#define vi vector<int>
#define vll vector<ll>
#define vdb vector<db>
#define vldb vector<ldb>
#define vpi vector< pi >
#define vpll vector< pll >

#define mi map<int,int>
#define mll map<ll,ll>
#define mdb map<db,db>
#define mldb map<ldb,ldb>


#define forr(i,a,b) for (int i = (a); i < (b); ++i)
#define rrof(i,a,b) for (int i = (b)-1; i >= (a); --i)


const int MOD = 1e9+7;
const ldb PI = 4*atan((ldb)1);

ll power(ll a,ll n){
	ll res=1;

	while(n){
		if(n%2)
		res*=a;
		a*=a;
		n/=2;
	}
	
	return res;
}

int main(){
	fast;
	
	string s;
	cin>>s;
	
	int cnta=0,cntb=0;
	forr(i,0,s.size()){
		if(s[i]=='A')
		cnta++;
		
		else
		cntb++;
	}
	
	if(cnta!=0 && cntb!=0)
	cout<<"Yes";
	
	else
	cout<<"No";
	return 0;
}
