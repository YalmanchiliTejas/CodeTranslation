#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(i=a;i<b;i++)
#define rloop(i,a,b) for(i=a;i>=b;i--)
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
const int inf=1000000001;
const ll INF=1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846

void fill(string &ans,string &s,int k);
bool check(string &ans,string &s,int k);

int main(){
	int n,i,j,k;
	cin>>n;
	string s;
	cin>>s;
	bool flag=false;
	string ans;
	loop(i,0,2){
		loop(j,0,2){
			ans.clear();
			if(i==0){
				ans+='S';
			}else{
				ans+='W';
			}
			if(j==0){
				ans+='S';
			}else{
				ans+='W';
			}
			loop(k,2,n){
				fill(ans,s,k);
			}
			flag=check(ans,s,n-1);
			if(flag){
				flag=check(ans,s,n);
			}
			if(flag){
				break;
			}
		}
		if(flag){
			break;
		}
	}
	if(!flag){
		cout<<-1<<endl;
	}else{
		loop(i,0,n){
			cout<<ans[i];
		}
		cout<<endl;
	}
}

void fill(string &ans,string &s,int k){
	if(s[k-1]=='o'){
		if(ans[k-1]=='S'){
			if(ans[k-2]=='S'){
				ans+='S';
			}else{
				ans+='W';
			}
		}else{
			if(ans[k-2]=='S'){
				ans+='W';
			}else{
				ans+='S';
			}
		}
	}else{
		if(ans[k-1]=='S'){
			if(ans[k-2]=='S'){
				ans+='W';
			}else{
				ans+='S';
			}
		}else{
			if(ans[k-2]=='S'){
				ans+='S';
			}else{
				ans+='W';
			}
		}
	}
}

bool check(string &ans,string &s,int k){
	int n=ans.size();
	if(s[k%n]=='o'){
		if(ans[k%n]=='S'){
			if(ans[(k-1)%n]==ans[(k+1)%n]){
				return true;
			}else{
				return false;
			}
		}else{
			if(ans[(k-1)%n]==ans[(k+1)%n]){
				return false;
			}else{
				return true;
			}
		}
	}else{
		if(ans[k%n]=='S'){
			if(ans[(k-1)%n]==ans[(k+1)%n]){
				return false;
			}else{
				return true;
			}
		}else{
			if(ans[(k-1)%n]==ans[(k+1)%n]){
				return true;
			}else{
				return false;
			}
		}
	}
}