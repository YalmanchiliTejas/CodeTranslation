#include <bits/stdc++.h>
using namespace std;
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define mp make_pair

ll ncr(ll n, ll r){
    if(n==r){
        return 1;
    }
    if(n<r){
        return 0;
    }else{
        ll temp=r;
        ll res=1;
        while(temp>0){
            res*=(n+temp-r);
            temp--;
            res/=(r-temp);
        }
        return res;
    }
}

int main(){
	fast;
	int test=1;
	//cin >> test;
	while(test--){
	    string n;
	    ll k;
	    cin >> n >> k;
	    ll len=n.length();
	    ll te=len;
	    ull ans=0;
	    ll temp=k;
	    for(int i=0 ; ; i++){
	        if(len<temp){
	            ans--;
	            break;
	        }else if(temp==0 || i==te){
	            break;
	        }
	        if(n[i]-'1'>=0){
	            ans+=ncr(len-1,temp)*pow(9,temp);
	            temp--;
	            ans+=(n[i]-'1')*ncr(len-1,temp)*pow(9,temp);
	        }
	        len--;
	    }
	    cout << ans+1 << endl;
	}
	return 0;
}