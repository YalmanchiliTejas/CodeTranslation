#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int h, w, cnt;
vector<vector<char>> as;

void solve(int y, int x, int cnt){
    if(y == h && x == w){
        cout << (cnt == ::cnt ? "Possible" : "Impossible") << endl;
        exit(0);
    }
    if(y == as.size() || x == as[0].size() || as[y][x] == '.'){ return; }
    solve(y + 1, x, cnt + 1);
    solve(y, x + 1, cnt + 1);
}

int main(){
	cin >> h >> w;
    vector<vector<char>> as(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> as[i][j];
            if(as[i][j] == '#'){
                cnt++;
            }
        }
    }
    as.swap(::as);
    h--; w--;
    solve(0, 0, 1);
    cout << "Impossible" << endl;
	return 0;
}

