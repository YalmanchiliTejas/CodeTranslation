#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

int N;
string  str;

string hoge(string ans){
	for(int i = 2; i < str.size(); i++){
		if(str[i-1] == 'o'){
			if(ans[i-1] == 'S'){
				ans += ans[i-2];
			} else {
				ans += (ans[i-2]=='S'?'W':'S');
			}
		} else {
			if(ans[i-1] == 'S'){
				ans += (ans[i-2]=='S'?'W':'S');
			} else {
				ans += ans[i-2];
			}
		}
	}
	if(ans[N-1] == 'S'){
		if(str[N-1] == 'o'){
			if(ans[0] != ans[N-2]) ans = "-1";
		} else {
			if(ans[0] == ans[N-2]) ans = "-1";
		}
	} else {
		if(str[N-1] == 'o'){
			if(ans[0] == ans[N-2]) ans = "-1";
		} else {
			if(ans[0] != ans[N-2]) ans = "-1";
		}
	}
	
	if(ans[0] == 'S'){
		if(str[0] == 'o'){
			if(ans[1] != ans[N-1]) ans = "-1";
		} else {
			if(ans[1] == ans[N-1]) ans = "-1";
		}
	} else {
		if(str[0] == 'o'){
			if(ans[1] == ans[N-1]) ans = "-1";
		} else {
			if(ans[1] != ans[N-1]) ans = "-1";
		}
	}
	return ans;
}

signed main(){
	cout<<fixed<<setprecision(7);

	string  ans[4] = {"SS","SW","WW","WS"};
	
	cin>>N>>str;
	
	for(int i = 0; i < 4; i++){
		string temp = hoge(ans[i]);
		if(temp != "-1"){
			cout<<temp<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}