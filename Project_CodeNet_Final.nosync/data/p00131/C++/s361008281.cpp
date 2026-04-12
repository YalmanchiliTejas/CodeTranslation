#include <iostream>
#include <cstring>
using namespace std;

int t[10][10],s[10][10],ans[10][10];
int dx[] = {0,-1,0,1,0};
int dy[] = {-1,0,0,0,1};

bool check(int *used){
	memset(ans,0,sizeof(ans));
	memcpy(s,t,sizeof(t));

	for(int i=0;i<10;i++){
		ans[0][i] = used[i];
		if(used[i]){
			for(int j=0;j<5;j++){
				int nx = i + dx[j];
				int ny = dy[j];

				if(nx>=0 && 10>nx && ny>=0 && 10>ny){
					s[ny][nx] = !s[ny][nx];
				}
			}
		}
	}

	for(int i=1;i<10;i++){
		for(int j=0;j<10;j++){
			if(s[i-1][j]){ //ツ湘」ツつェ1ツづ按づァツづ篠必ツつクツ古オツつェツ必ツ要
				ans[i][j] = 1;
				for(int k=0;k<5;k++){
					int nx = j + dx[k];
					int ny = i + dy[k];

					if(nx>=0 && 10>nx && ny>=0 && 10>ny){
						s[ny][nx] = !s[ny][nx];
					}
				}
			}
		}
	}

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(s[i][j]) return false;
		}
	}
	return true;
}

bool solve(int idx,int *used){
	if(idx == 10){
		if(check(used)){
			return true;
		}
		return false;
	}

	if(solve(idx+1,used)) return true;
	used[idx] = 1;
	if(solve(idx+1,used)) return true;
	used[idx] = 0;

	return false;
}

int main(void){
	int n;
	cin>>n;

	while(n--){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cin>>t[i][j];
			}
		}

		int used[10];
		memset(used,0,sizeof(used));
		solve(0,used);

		for(int i=0;i<10;i++){
			for(int j=0;j<9;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<ans[i][9]<<endl;
		}
	}

	return 0;
}