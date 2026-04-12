#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

string FizzBuzz(int n){
	string res="";
	if(n%3==0) res+="Fizz";
	if(n%5==0) res+="Buzz";
	if(res==""){
		stringstream ss;
		ss<<n;
		ss>>res;
	}
	return res;
}

signed main(){
	int m,n;
	while(1){
		cin>>m>>n;
		if(m+n==0) break;
		vector<string> s(n+1);
		rep(i,1,n+1) cin>>s[i];
		vi d(m);
		rep(i,0,m) d[i]=i+1;
		int now=0;

		rep(i,1,n+1){
			//cout<<s[i]<<" "<<FizzBuzz(i)<<endl;
			if(s[i]==FizzBuzz(i)){
				now++;
			}else{
				d.erase(remove(all(d),d[now]),d.end());
			}
			if(d.size()==1) break;
			now%=d.size();
		}
		rep(i,0,d.size()){
			cout<<(i?" ":"")<<d[i];
		}
		cout<<endl;
	}
}