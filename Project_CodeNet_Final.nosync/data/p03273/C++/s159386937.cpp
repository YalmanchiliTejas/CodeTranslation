#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 10000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	map<int, int> storageX;
	map<int, int> storageY;
	
	cin >> h >> w;
	
	char arr[h][w];
	vector<char> col;
	vector<vector<char> > ans;
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> arr[i][j];		
		}
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(arr[i][j] == '.') storageX[i]++;
		}
	}

	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			if(arr[j][i] == '.') storageY[i]++;
		}
	}
	
	for(int i = 0; i < h; i++){
		if(storageX[i] == w) continue;
		for(int j = 0; j < w; j++){	
			if(storageY[j] == h) continue;
			col.push_back(arr[i][j]);
		}
		ans.push_back(col);
		col.clear();
	}
	
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
