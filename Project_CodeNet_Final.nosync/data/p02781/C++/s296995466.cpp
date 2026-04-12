#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string num;
int k;

int dfs(int idx,bool limit,int k){
	if(k<0) return 0;
	if(k==0) return 1;
	if(idx==0) {
		if(k>1) return 0;
		else if(k==0) return 1;
		else {
			if(limit) return num[idx]-'0';
			else return 9;
		} 
	}
	int up = limit? num[idx]-'0' : 9;
	if(up==0) return dfs(idx-1,limit,k);
	else if(limit) return dfs(idx-1,limit,k-1)+dfs(idx-1,false,k-1)*(up-1)+dfs(idx-1,false,k);
	else return dfs(idx-1,false,k-1)*up + dfs(idx-1,false,k);

}

int main(){
	//freopen("in","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> num >> k;
	reverse(num.begin(),num.end());
	int res = dfs(num.size()-1,true,k);
	cout << res << endl;
}