#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long ll;

ll solve1(string s,int l,int n){
	ll res=0;
	ll val=1;
	for(int i=l;i<n;i++){
		if(s[i]=='*')continue;
		else if(s[i]=='+'){
			res+=val;
			val=1;
		}
		else{
			val*=(s[i]-'0');
		}
	}
	res+=val;
	return res;
}

ll solve2(string s,int l,int n){
	ll res=s[0]-'0';
	char op='+';
	for(int i=1;i<n;i++){
		if(s[i]=='+'||s[i]=='*'){
			op=s[i];
		}else{
			if(op=='+'){
				res+=(s[i]-'0');
			}else{
				res*=(s[i]-'0');
			}
		}
	}
	return res;
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	ll n; cin >> n;
	if(n==solve1(s,0,s.size())){
		if(n==solve2(s,0,s.size())){
			printf("U\n");
		}else{
			printf("M\n");
		}
	}else{
		if(n==solve2(s,0,s.size())){
			printf("L\n");
		}else{
			printf("I\n");
		}
	}
}
