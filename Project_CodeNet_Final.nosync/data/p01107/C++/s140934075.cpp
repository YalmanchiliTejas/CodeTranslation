#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

#define MAX
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int con;
int h, w, v;

vector<string> field;
vector<vector<bool>> visited;

bool solve(int x = 0, int y = 0, int xd = 0, int yd = 0, int z = 0){

	int nx ,ny , rx , ry;
	
	if(z < v) return false;
	v |= z;
	if(x == 0 && y == 0 && visited[y][x] && z == 7) return true;
	if(visited[y][x] == true) return false;
			
	visited[y][x] = true;
	
	for(int i = 0; i < 16; i++){
		nx = x + dx[xd], ny = y + dy[yd], rx = nx + dx[(xd+1)%4], ry = ny + dy[(yd+1)%4];
		if(nx < 0 || nx >= w || ny < 0 || ny >= h || field[ny][nx] == '#' || ((ny == 0 && nx == 0)? 0:visited[ny][nx])){
			xd = (xd + 3)%4, yd = (yd + 3)%4;
			continue;
		}
		
		if(rx >= 0 && rx < w && ry >= 0 && ry < h && (field[ry][rx] == '.')) xd = (xd + 1)%4, yd = (yd + 1)%4;

		
		if(y == h-1 && x == 0) z |= (1<<0);
		if(y == h-1 && x == w-1) z |= (1<<1);
		if(y == 0 && x == w-1) z |= (1<<2);
		
		if(solve(nx, ny, xd, yd, z)) return true;
	}
	
	
	
	return false;
}
signed main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	// cout<<fixed<<setprecision(10);
	
	
	
	while(true){
		v = 0;
		
		cin>>h>>w;
		if(!h && !w) break;
		
		field.clear();
		visited.clear();
		field.resize(h);
		visited.resize(h, vector<bool>(w, false));
		
		for(int i = 0; i < h; i++){
			cin>>field[i];
		}

		
		cout<<YN(solve())<<endl;
	}
	
	
	return 0;
}
