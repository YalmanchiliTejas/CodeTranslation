#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int H, W;
vector<string> grid;

int main(void){
	
	scanf("%d %d", &H, &W);
	for(int i = 0; i < H; ++i){
	    string s; cin >> s;
	    int num = 0;
	    for(auto j : s) if(j == '.') ++num;
	    if(num != W) grid.push_back(s); 
	}
    
    for(int j = 0; j < W; ++j){
        int num = 0;
        for(int i = 0; i < grid.size(); ++i) if(grid[i][j] == '.') ++num;
        if(num == grid.size()){
            for(int i = 0; i < grid.size(); ++i){
                grid[i].erase(grid[i].begin() + j);
            }
            --j;
        }
    }
    
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j) cout << grid[i][j];
        cout << endl;
    }
    
    return 0;
}