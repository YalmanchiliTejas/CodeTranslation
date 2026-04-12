#include <bits/stdc++.h>
using namespace std;
#define ff        first
#define ss        second
#define ll        long long
#define int       long long
#define inf       ((ll)1e18)
#define mod       1000000007
#define double    long double
#define ull       unsigned long long
#define vi        vector<ll>
#define ppi       pair<int,int>
#define pii       pair<pair<int,int>,int>
#define pb        push_back
#define pi        2*acos(0.0)
#define rev       greater<int>()
#define pr(a,x,y) for(int i=x;i<y;i++){cout<<a[i]<<" ";}
#define sp(x,y)   fixed<<setprecision(y)<<x
#define w(x)      ll x; cin>>x; while(x--)
#define all(v)    v.begin(), v.end()
#define rall(v)   v.rbegin(), v.rend()
#define test      cout<<"This is test"<<endl;
#define str       string
#define endl      '\n'
#define e         cout<<'\n';
void kehsihba(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
}
/*ll get(ll *arr,ll low,ll high,ll n){
	int mid=low+(high-low)/2;
	if((mid==0 or arr[mid-1]<=arr[mid]) and (mid==(n-1) or arr[mid+1]<=arr[mid])){
		return arr[mid];
	}
	else if(mid>0 and arr[mid-1]>arr[mid]){
		return get(arr,low,mid-1,n);
	}
	else{
		return get(arr,mid+1,high,n);
	}
}*/
/*ll get(int *arr,int n,int left,int i){
	if(i==n){return 1;}
	int curr=arr[i];
	int right=get(arr,n,arr[i]*left,i+1);
	arr[i]=left*right;
	return curr*right;
}*/
/*ll get(int *arr,int n){
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		int prev=(mid-1+n)%n;
		int next=(mid+1)%n;
		if(arr[mid]<=arr[prev] and arr[mid]<=arr[next]){
			return mid;
		}
		else if(arr[low]<=arr[mid]){
			low=mid+1;
		}
		else if(arr[high]>=arr[mid]){
			high=mid-1;
		}
	}
}*/
/*void get(map<str,int>&m,str s,str ans=""){
	if(s.size()==0){cout<<ans;e;return;}
	for(int i=1;i<=(int)s.size();i++){
		str x=s.substr(0,i);
		if(m[x]){
			get(m,s.substr(i),ans+" "+x);
		}
	}
}*/
void solve(){
	ll n;cin>>n;
	ll arr[n];
	ll x=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		x+=arr[i];
	}
	int product=0;
	int sum=arr[n-1];
	for(int i=n-2;i>=0;i--){
	product = ((product%mod) + ((arr[i]%mod)*(sum%mod))%mod)%mod;
	sum = sum + arr[i];
	}
	cout<<product;
}
int32_t main(){
	kehsihba();
	//init();
	ll t=1;
	//cin>>t;
	for(int k=1;k<=t;k++){
		//cout<<"Case #"<<k<<": ";
		solve();
		//e;
	}
}
