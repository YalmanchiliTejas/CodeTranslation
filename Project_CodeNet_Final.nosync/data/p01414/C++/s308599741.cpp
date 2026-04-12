#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int calc(int a,int b){
	int tmp = 1;
	for(int ccc=0;ccc<4*a;ccc++){
		tmp*=2;
	}
	for(int j=0;j<b;j++){
		tmp*=2;
	}
	return tmp;
}

int main(){
	int n;
	cin >> n;
	vector<pair<int,int> > p;
	for(int i=0;i<n;i++){
		int h,w;
		cin >> h >> w;
		p.PB(MP(h,w));
	}
	set<vector<pair<int,int> > >sp;
	for(int qq=0;qq<n;qq++){
		for(int i=-3;i<=3;i++){
			for(int j=-3;j<=3;j++){
				vector<pair<int,int> > z;
				for(int x = 0;x<p[qq].first;x++){
					for(int y=0;y<p[qq].second;y++){
						if(i+x>=0&&i+x<=3&&j+y>=0&&j+y<=3){
							z.PB(MP(i+x,j+y));
						}
					}
				}
				if(z.size()!=0)sp.insert(z);
			}
		}
	}
	//cout << sp.size() << endl;
	string s[4];
	for(int i=0;i<4;i++){
		cin >> s[i];
	}
	int a[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[i][j]=='R'){
				a[i][j] = 1;
			}else if(s[i][j]=='G'){
				a[i][j] = 2;
			}else{
				a[i][j] = 3;
			}
		}
	}
	int ans=0;
	queue<pair<int,int > >q;
	bool used[100010];
	used[0] = 1;
	q.push(MP(0,0));
	set<int> st;
	bool breakflag=0;
	while(!q.empty()){
		auto x = q.front();
		q.pop();
		int f = x.first;
		int g = x.second;
		if(f==65535){
			ans = g;
			break;
		}
			for(auto w:sp){
				for(int c=1;c<4;c++){
					int s = f;
					for(int i=0;i<w.size();i++){
						if(a[w[i].first][w[i].second]==c){
							s |= calc(w[i].first,w[i].second);
						}else{
							if((s&calc(w[i].first,w[i].second))==calc(w[i].first,w[i].second)){
								s -= calc(w[i].first,w[i].second);
							}	
						}
					}
					if(s==65535){
						ans = g+1;
						breakflag = 1;
						break;
					}
					if(used[s]!=1){
						//cout << static_cast<bitset<16> > (f) << " " << static_cast<bitset<16> > (s) << endl;
						used[s]=1;
						q.push(MP(s,g+1));
					}
				}
				if(breakflag)break;	
			}
			if(breakflag)break;
		
		if(breakflag)break;
	}
	cout << ans << endl;
	return 0;
}



