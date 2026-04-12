#include<bits/stdc++.h>
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
#define si size()
#define mp make_pair 
#define mt make_tuple
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound

#define ask(i,m,n) for(lli i=m;i<n;i++)
#define anket ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
 
#define endl "\n"
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout<<a<<" "<<b<<"\n"
#define o3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
using namespace std;

#define prime1 1000000007
#define prime2 998244353

lli modadd(lli n,lli m , lli mod){
    lli sum = ((n+m)%mod+mod)%mod;
    return sum;
}

lli modsub(lli n,lli m,lli mod){
    lli diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}

lli modpro(lli n,lli m, lli mod){
    lli pro = ((n*m)%mod+mod)%mod;
    return pro;
}

lli powmod(lli x,lli y,lli mod){
    x %= mod;
    y %= mod;
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x,mod);
        y = y >> 1;
        x = modpro(x , x,mod);
    }
    return res;
}

lli moddiv(lli n,lli m,lli mod){
    //return n/m mod (mod) or n*(m)^-1 mod (mod)
    lli a = powmod(m,mod-2,mod);
    //this is because of fermats thm i.e. a^-1 = a^p-2 mod(p) check
    //multiplying p on both sides
    lli res = modpro(a,n,mod);
    return res;
}

vector<lli> prefix_function(string s) {
    lli n = (lli)s.length();
    vector<lli> pi(n);
    for (lli i = 1; i < n; i++) {
        lli j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
	anket;
	lli n;
	cin>>n;
	lli a[n];
	ask(j,0,n){
	    cin>>a[j];
	}
	lli b = n/2;
	lli c[n];
	lli d[n];
	if(n %2==0){
	    c[0] = a[0];
	    c[1] = a[1];
	    d[0] = 0;
	    d[1] = 1;
	    ask(i,2,n){
	        c[i] = a[i] + c[i-2];
	        i++;
	        c[i] = max(a[i]+c[i-3],a[i] + c[i-2]);
	    }
	    lli ans = max(c[n-1],c[n-2]);
	    o1(ans);
	    return 0;
	}
	else{
	    c[0] = a[0];
	    c[1] = a[1];
	    ask(i,2,n-1){
	        c[i] = a[i] + c[i-2];
	        i++;
	        c[i] = max(a[i]+c[i-3],a[i] + c[i-2]);
	    }
	    d[n-1] = a[n-1];
	    d[n-2] = a[n-2];
	    for(lli j=n-3;j>=1;j--){
	        d[j] = a[j] + d[j+2];
	        j--;
	        d[j] = max(a[j] + d[j+2] , a[j] + d[j+3]);
	    }
	    lli ans = max(c[n-2],c[n-3]);
	    ans = max(ans, d[1]);
	    ans = max(ans, d[2]);
	    for(lli i=0;i+3 < n;i++){
	        ans = max(ans, c[i]+d[i+3]);
	        if(i+4<n && i %2==0){
	            ans = max(ans , c[i] + d[i+4]);
	        };
	        
	    }
	    o1(ans);
	}
	return 0;
}


