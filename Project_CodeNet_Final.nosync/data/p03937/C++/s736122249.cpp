#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

#define inf  1000000007
#define ll long long
#define PA pair<int,int>
#define PPAP pair<int,PA>
#define  MP make_pair
#define  PB push_back

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	vector<string>s(h);
	for(int i=0;i<h;i++){
		cin >> s[i];
	}
	int x=0,y=0;
	vector<vector<bool> > flag(h,vector<bool>(w));
	flag[x][y] = 1;
	bool pos=0;
	while(1){
		if(y==w-1&&x==h-1){
			flag[x][y] = 1;
			break;	
		}
		if(y==w-1){
			if(s[x+1][y]=='#'){
				x++;
				flag[x][y]=1;
			}else{
				pos = 1;
				break;
			}
		}else if(x==h-1){
			if(s[x][y+1]=='#'){
				y++;
				flag[x][y]=1;
			}else{
				pos = 1;
				break;
			}
		}else{
			if(s[x+1][y]=='#'){
				x++;
				flag[x][y] = 1;
			}else if(s[x][y+1]=='#'){
				y++;
				flag[x][y] = 1;
			}else{
				pos = 1;
				break;
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(flag[i][j]!=1&&s[i][j]=='#'){
				pos = 1;
			}
		}
	}
	if(pos){
		cout << "Impossible" << endl;
	}else{
		cout << "Possible" << endl;
	}
	return 0;
}