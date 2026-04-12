// 	Divyanshu Srivastava

#include <bits/stdc++.h>
#define t(w) ll w; cin>>w; while(w--) 
#define ipv(v,n) for(ll i=0;i<n;i++){ll a; cin>>a; v.push_back(a);}
#define op(v) for(auto it=v.begin();it<v.end();it++) cout<<*it;
#define opm(m) for(auto it=m.begin();it<m.end();it++) cout<<it->first<<" "it->second<<endl;
typedef long long int ll; 
typedef unsigned long long int ull; 
// __builtin_popcount(n));
// lower_bound(v.begin(),v.end(),30);
// binary_search(v.begin(),v.end(),30)   returns bool t/f

using namespace std;

vector<ll> seve(1000001,1);

void create_seve(){
	seve[0]=0;
	seve[1]=0;
    for(ll i=2;i<=1000000;i++){
        for(ll j=2;j*j<=i;j++){
            if(i%j==0){
                seve[i]=0;
                break;
            }
        }
    }
}

bool is_prime(ll n){
	// create_seve();
    return seve[n];
} 

vector<pair<ll,ll>> prime_factorization(ll n){
	vector<pair<ll,ll>> pf;
	for(ll i=2;i*i<=n;i++){
		ll c=0;
		while(n%i==0){
			c++;
			n/=i;
		}
		if(c!=0)
			pf.push_back(make_pair(i,c));	
	}
	if(n>1)
		pf.push_back(make_pair(n,1));
	return pf;
}

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ull power(ull a,ull n){
	ull ans=1;
	while(n>0){
		if(n&1){
			ans*=a;
		}
		a*=a;
		n=n>>1; 
	}
	return ans;
}

ull modulo_power(ull a,ull n,ull m){
	ull ans=1;
	while(n>0){
		if(n&1){
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		n=n>>1; 
	}
	return ans%m;
}

ll sumofdig(ll ds){
	ll ans=0;
	while(ds){
		ans+=ds%10;
		ds=ds/10;	
	}
	return ans;
}

void solve1(){ //keep this code digjump cc (bfs)
//mistake is in calulation of ditance
	string s;
	cin>>s;
	unordered_map<ll,list<ll>> m;
	for(ll i=0;i<s.size();i++){
		m[s[i]-'0'].push_back(i);
	}
	for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<"->";
		for(auto a:it->second){
			cout<<a<<",";
		}
		cout<<endl;
	}
	queue<ll> q;
	map<ll,bool> visited;
	q.push(0);
	visited[0]=true;
	vector<ll> dis(100001,0);
	while(!q.empty()){
		ll temp=q.front();
		q.pop();
		if(temp==s.size()-1)
			break;
			
		// cout<<temp<<" ";
		for(ll a:m[s[temp]-'0']){
			if(!visited[a]){
				dis[a]=dis[temp]+1;
				q.push(a);
				visited[a]=true;
			}
		}
		if(temp==0 and !visited[1]){
			dis[1]=dis[temp]+1;
			q.push(1);
			visited[1]=true;
		}
		else{ 
			if(!visited[temp-1]){
				dis[temp-1]=dis[temp]+1;
				q.push(temp-1);
				visited[temp-1]=true;
			}
			if(!visited[temp+1]){
				dis[temp+1]=dis[temp]+1;
				q.push(temp+1);		
				visited[temp+1]=true;
			}
		}
	}
	cout<<dis[s.size()-1]<<endl;
}

void solve(){
	ll n;
	string s;
	cin>>n;
	cin>>s;
	ll c=0,ans=0;
	for(ll i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			c++;
		}
		else{
			c=0;
		}
		if(c>1){
			ans++;
			c=0;
		}
	}
	if(s[n-1]==s[0]){
		c++;
	}
	if(c>1)
		cout<<ans+1<<endl;
	else{
		cout<<ans<<endl;
	}
}

void solve2(){//kickstart august high buildings  
	ll q;
	cin>>q;
	for(ll i=1;i<=q;i++){
		vector<ll> v;
		ipv(v,4);

		vector<ll> ans(v[0],1);
		ll pos=0;
		if(v[0]>=(v[1]+v[2]-v[3])){
			for(ll i=0;i<v[1]-v[3];i++){
				ans[i]=v[0]-1;
			}
			if(v[1]-v[3]>0){
			    for(ll i=v[1]-v[3];i<v[0]-(v[1]+v[2]-v[3]);i++){
					ans[i]=1;
				}
			}
			for(ll i=1;i<=v[3];i++){
				ans[pos]=v[0];
				pos++;
			}
			for(ll i=0;i<v[2]-v[3];i++){
				ans[v[0]-i-1]=v[0]-1;
			}
			cout<<"Case #"<<i<<": ";
			op(ans);
			cout<<endl;
		}
		else{
			cout<<"Case #"<<i<<": IMPOSSIBLE\n";
		}
	}
}

void solve3(){
	ll x;
	string s;
	cin>>s;
	cin>>x;
	vector<ll> v(s.size(),1);
	ll c=-1;
	for(ll i=0;i<s.size();i++){
		if(c!=-1 and i-c>=2*x){
			cout<<-1<<endl;
			return;
		}
		if(s[i]==0){
			c=i;
			if(i-x>=0 and i+x<s.size()){
					v[i+x]=0;
					v[i-x]=0;
			}
			else if(i-x>=0){
					v[i-x]=0;
			}
			else if(i+x<s.size()){
					v[i+x]=0;
			}
		}
	}
	op(v);
	cout<<endl;
}


void solve4(){
	ll n;
	cin>>n;
	vector<ll> v,p(n,0);
	ipv(v,n);
	p[n-1]=v[n-1];
	for(ll i=n-2;i>-1;i--){
		p[i]=v[i]+p[i+1];
	}
	ll ans=0;
	for(ll i=0;i<n-1;i++){
		ans=ans+((v[i]%1000000007)*(p[i+1]%1000000007)%1000000007);
		ans=ans%1000000007;
	}
	cout<<ans<<endl;
}


//always call create_seve() in main()
int main(){
	//create_seve();
	//LEARN ABOUT FAST INPUT AND OUTPUT MORE
	// ios_base::sync_with_stdio(false);       
	// cin.tie(NULL);
	// cout.tie(NULL);
	{
		solve4();
	}
	// ll n;
	// cin>>n;
	// vector<ll> v{1,2,3,4,5,6,6,7,8};
	// auto a=lower_bound(v.begin(),v.end(),2);
	// auto b=upper_bound(v.begin(),v.end(),2);
	// cout<<a-v.begin()<<" "<<(b-v.begin());
	// ipv(v,n);
	// op(v);
	// vector<pair<ll,ll>> a=prime_factorization(999983);
	// for(pair<ll,ll> b:a){
	// 	cout<<b.first<<" "<<b.second<<"\n";
	// }
	//cout<<ceil();
	//vector<ll> v{1,2,3,4,5};
	//cout<<v;
	return 0;
}
