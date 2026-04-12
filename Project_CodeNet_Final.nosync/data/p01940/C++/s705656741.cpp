#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define reep(i,a,b) for(int i=a; i<b; i++)
#define MOD 1000000007
#define INFL 0x3f3f3f3f3f3f3f3f

using ll = long long;

int main(){
	string s;
	cin>>s;
	string p;
	cin>>p;
	int n = s.size();
	int m = p.size();
	vector<int> pos1(p.size(),-1);
	auto pos2 = pos1;
	int cnt = 0;
	rep(i,n){
		if(cnt<m){
			if(p[cnt] == s[i]){
				pos1[cnt] = i;
				cnt++;
			}
		}
	}
	cnt = m-1;
	for(int i=n-1; i>=0; i--){
		if(cnt>=0){
			if(p[cnt] == s[i]){
				pos2[cnt] = i;
				cnt--;
			}
		}
	}
	if(pos1[m-1]>=0&&pos2[0]>=0){
		rep(i,m){
			if(pos1[i] != pos2[i]){
				cout<<"no"<<endl;
				return 0;
			}
		}
		cout<<"yes"<<endl;
		return 0;
	}
	cout<<"no"<<endl;
}