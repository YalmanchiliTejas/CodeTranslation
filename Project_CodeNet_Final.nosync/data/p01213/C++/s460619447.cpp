#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int sz1 , sz2;
string s;

vector<int> c[128];
int off[128][322];
int dp[301][301];
pair<int,int> to[301][301];
int flag[301][301];

int dp_search(int sz1,int sz2){
	memset(dp,-1,sizeof(dp));
	memset(flag,0,sizeof(flag));
	int r;
	dp[0][sz1] = 0;
	to[0][sz1] = make_pair(-1,-1);
	for(int p1 = 0 ; p1 <= sz1 ; p1++){
		for(int p2 = sz1 ; p2 <= sz2 ; p2++){
			if(dp[p1][p2] != -1){
				if(p1 < sz1){
					int i = off[s[p1]][p2];
					if(i != 9999){
						r = dp[p1][p2]+1;
						if(r>dp[p1+1][i+1]){
							to[p1+1][i+1] = make_pair(p1,p2);
							dp[p1+1][i+1] = r;
							flag[p1+1][i+1] = 1;
						}
					}
					r = dp[p1][p2];
					if(r > dp[p1+1][p2]){
						to[p1+1][p2] = make_pair(p1,p2);
						dp[p1+1][p2] = r;
					}
				}
				if(p2 < sz2){
					r = dp[p1][p2];
					if(r > dp[p1][p2+1]){
						to[p1][p2+1] = make_pair(p1,p2);
						dp[p1][p2+1] = r;	
					}
				}
			}
		}
	}
	return dp[sz1][sz2];
}
string get(int sz1,int sz2){
	string ans = "";
	while(sz1 != -1){
		int x = to[sz1][sz2].first;
		int y = to[sz1][sz2].second;
		if( flag[sz1][sz2] ){
			ans = string(1,s[x]) + ans;
		}
		sz1 = x;
		sz2 = y;
	}
	return ans;
}

int main(){
	while(cin >> s && s[0] != '#'){
		int last[26];
		for(int i = 0 ; i < 26 ; i++) last[i] = 9999;
		for(int i = s.size() ; i >= 0 ; i--){
			last[s[i]-'A'] = i;
			for(int j = 0 ; j < 26 ; j++){
				off[j+'A'][i] = last[j];
			}
		}
		int save[333]={0};
		int currentmx = 0;
		for(int i = 1 ; i < s.size() ; i++){
			sz1 = i; sz2 = s.size();
			if(min(sz1,sz2-sz1) <= currentmx ) continue;
			save[i] = dp_search(sz1,sz2);
			currentmx = max(save[i],currentmx);
		}
		for(int i = 1 ; i < s.size() ; i++){
			if(save[i] == currentmx){
				sz1 = i; sz2 = s.size();
				dp_search(sz1,sz2);
				cout << get(sz1,sz2) << endl;
				break;
			}
		}
	}
}