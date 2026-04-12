#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pi pair<ll,ll>
int n;
char s[101000];
char ans[101000];
bool check(){
	for (int i = 1; i < n-1; ++i)
	{
		if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
			ans[i-1] =='S' ? ans[i+1]='S' :ans[i+1] = 'W';
		}else{
			ans[i-1] =='S' ? ans[i+1]='W' :ans[i+1] = 'S';
		}
	}
	if((ans[n-1]=='S'&&s[n-1]=='o')||(ans[n-1]=='W'&&s[n-1]=='x')){
		if(ans[0]!=ans[n-2]){
			return false;
		}
	}else{
		if(ans[0]==ans[n-2]){
			return false;
		}
	}
	if((ans[0]=='S'&&s[0]=='o')||(ans[0]=='W'&&s[0]=='x')){
		if(ans[1]!=ans[n-1]){
			return false;
		}
	}else{
		if(ans[1]==ans[n-1]){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> n;
	cin >> s;
	int i;
	for (i = 0; i < 4; ++i)
	{
		ans[0]= (i/2==0)?'S':'W';
		ans[1]= (i%2==0)?'S':'W';
		if(check()) break;
	}
	if(i==4){
		cout << "-1" << endl;
	}else{
		ans[n]='\0';
		cout << ans << endl;
	}
	// freopen("in.txt","r",stdin);
	return 0;
}
