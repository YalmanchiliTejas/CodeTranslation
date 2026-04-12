#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define pb push_back

const int N = 16;
const int W = 4;
const int INF = 1000000007;
const int BITMAX = (1<<(W*W));

int n;
int sh[N];
int sw[N];

vector<string> color;


void input(){
	cin>>n;
	rep(i,n)cin>>sh[i]>>sw[i];
	
	rep(i,W){
		string str;
		cin>>str;
		color.pb(str);
	}
}

bool hasbit(int state, int i){
	return (state&(1<<i))>0;
}

bool printbit(int state){
	rep(i,W*W)printf("%d",(state&(1<<i))>0 ? 1:0);
}

class Board{
	public:
	int state;
	Board(int state):state(state){}
	
	char getMasuChar(int x,int y){
		int num = y*W + x;
		if((state&(1<<num))>0)return '?';
		return color[y][x];
	}
	
	bool canput(int index,int x,int y){
		int r=0,g=0,b=0;
		rep(i,sh[index]){
			rep(j,sw[index]){
				int nx = x+j;
				int ny = y+i;
				
				if(nx<0 || ny<0 || nx>=W || ny>=W)continue;
				
				char c = getMasuChar(nx, ny);
				if(c=='R')r++;
				if(c=='G')g++;
				if(c=='B')b++;
			}
		}
		if(r>0 && g==0 && b==0)return true;
		if(r==0 && g>0 && b==0)return true;
		if(r==0 && g==0 && b>0)return true;
		return false;
	}
	
	void put(int index,int x,int y){
		rep(i,sh[index]){
			rep(j,sw[index]){
				int nx = x+j;
				int ny = y+i;
				
				if(nx<0 || ny<0 || nx>=W || ny>=W)continue;
				
				int num = ny*W + nx;
				state |= (1<<num);
			}
		}
	}
	
	int getState(){
		return state;
	}
	
	void print(){
		printf("----------------------------\n");
		rep(i,W){
			rep(j,W){
				printf("%c ",getMasuChar(i,j));
			}puts("");
		}
	}
};

int memo[BITMAX];

int saiki(int state){
	if(state == (1<<(W*W))-1)return 0;
	if(memo[state]!=-1)return memo[state];
	
	Board b = Board(state);
	int ret = INF;
	
	rep(i,n){
		reps(y, 1-sh[i], W){
			reps(x, 1-sw[i], W){
				if(b.canput(i, x, y)){
					Board copy = b;
					copy.put(i, x, y);
					
					ret = min(ret, saiki(copy.getState())+1);
				}
			}
		}
	}
	
	return memo[state] = ret;
}

void solve(){
	rep(i,BITMAX)memo[i]=-1;
	
	int ans = saiki(0);
	cout<<ans<<endl;
}


int main(){
	input();
	solve();
}