#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,i,l,r,sum=0,sum1=0,mx,sum2=0;
	cin>>n;
	ll a[n];
	vector<ll> vi,vi1,vi2;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	sort(a,a+n);
	if(n%2==1){
	    vi.pb(a[n/2]);
	    l=0;;
	    r=n-1;
	    while(l<r){
	        vi.pb(a[r]);
	        r--;
	        vi.pb(a[l]);
	        l++;
	    }
	    if(n>=3){
	        l=0;;
    	    r=n-1;
    	    vi1.pb(a[n/2 -1]);
    	    while(l<r){
    	        vi1.pb(a[r]);
    	        r--;
    	        vi1.pb(a[l]);
    	        l++;
    	    }
    	    vi1.pop_back();
    	    vi1.pb(a[n/2]);
    /*	    for(auto x:vi1){
    	        cout<<x<<" ";
    	    }
    	    cout<<endl;*/
    	    l=0;;
    	    r=n-1;
    	    vi2.pb(a[1+n/2]);
    	    while(l<r){
    	        vi2.pb(a[l]);
    	        l++;
    	        vi2.pb(a[r]);
    	        r--;
    	    }
    	    vi2.pop_back();
    	    vi2.pb(a[n/2]);
    /*	    for(auto x:vi2){
    	        cout<<x<<" ";
    	    }
    	    cout<<endl;*/
	    }
	    for(i=0;i<n-1;i++){
	        sum+=(abs(vi[i]-vi[i+1]));
	    }
	    for(i=0;i<n-1;i++){
	        sum1+=(abs(vi1[i]-vi1[i+1]));
	    }
	    for(i=0;i<n-1;i++){
	        sum2+=(abs(vi2[i]-vi2[i+1]));
	    }
	    mx=max({sum,sum1,sum2});
	   /* for(auto x:vi){
	        cout<<x<<" ";
	    }
	    cout<<endl;*/
	    cout<<mx<<endl;
	}
	else{
	    vi.pb(a[n/2]);
	    l=0;;
	    r=n-1;
	    while(l<r && (l!= n/2 -1) &&(r!= n/2 -1)){
	        vi.pb(a[r]);
	        r--;
	        vi.pb(a[l]);
	        l++;
	    }
	    vi.pb(a[n/2 -1]);
	    vi1.pb(a[n/2 -1]);
	    l=0;;
	    r=n-1;
	    while(l<r){
	        vi1.pb(a[r]);
	        r--;
	        vi1.pb(a[l]);
	        l++;
	    }
	    vi1.pop_back();
	    for(i=0;i<n-1;i++){
	        sum+=(abs(vi[i]-vi[i+1]));
	    }
	    for(i=0;i<n-1;i++){
	        sum1+=(abs(vi1[i]-vi1[i+1]));
	    }
	    mx=max(sum1,sum);
	    cout<<mx;
	}
}