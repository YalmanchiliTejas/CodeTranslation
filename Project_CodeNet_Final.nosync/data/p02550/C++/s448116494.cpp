#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
	ll n,x,m;
	cin>>n>>x>>m;
	ll sum = x,ind=-1;
	set<ll> s;
	s.insert(sum);
	ll psum=0,nsum=0;
	vector<ll> a,b;
	b.push_back(sum);
	for(auto i=2;i<=n;i++){
	    ll num = (x*x)%m;
	    ll sz = s.size();
	    s.insert(num);
	    if(s.size() > sz){
	        sum += num;
	        x = num;
	        b.push_back(num);
	    }
	    else{
	        ind = i;
	        int f=0;
	        for(auto it = b.begin();it != b.end();it++){
	            if(f == 1){
	                nsum += *it;
	                a.push_back(nsum);
	                continue;
	            }
	            if(*it == num){
	                f = 1;
	                nsum += *it;
	                a.push_back(nsum);
	            }
	            else{
	                psum += *it;
	            }
	        }
	        break;
	    }
	}
	    if(ind == -1){
	        cout<<sum;
	    }
	    else{
	       // cout<<psum<<" "<<nsum<<" ";
	        ll diff  = n-ind+1;
	        ll tot = diff/a.size();
	        ll rem = diff%a.size();
	        nsum += (nsum * tot);
	        if(rem > 0){
	        nsum += a[rem-1];
	        }
	        cout<<(psum+nsum);
	    }
	return 0;
}
