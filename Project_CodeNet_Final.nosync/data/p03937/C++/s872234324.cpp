#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;cin >> h >> w;
	vector<string> s(h+1);
	rep(i,h) cin >> s.at(i);
	rep(i,h){
		s[i]+='.';
	}
	rep(i,w+1){
		s[h]+='.';
	}
	int cnt=0,sum=1;
	rep(i,h){
		rep(j,w){
			if(s[i][j]=='#') cnt++;
		}
	}
	int i=0,j=0;
	bool ans=true;
	while(i!=h-1 || j!=w-1){
		if(s[i+1][j]=='#' && s[i][j+1]=='#'){
			ans=false;
			break;
		}
		else if(s[i+1][j]=='.' && s[i][j+1]=='.'){
			ans=false;
			break;
		}
		else if(s[i+1][j]=='#'){
			i++;
			sum++;
		}
		else{
			j++;
			sum++;
		}
	}
	if(ans && cnt==sum) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}