#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n,H,W;
int memo[65536];
int visi[65536];
int Q[65537];
int head = 0 , size = 0;
vector<int> mask1,mask2;

vector< vector<char> > goal(4,vector<char>(4));

int w[20],h[20];

inline void gen(int s,int x,int y){
	rep(k,3){
		int a=0,b=0;
		rep(i,h[s]){
			rep(j,w[s]){
				int tx = x + j;
				int ty = y + i;
				if(tx >= 0 && tx < 4 && ty < 4 && ty >= 0){
						a |= 1<<(ty*4+tx);
						b |= (goal[ty][tx] == k)<<(ty*4+tx);
				}
			}
		}
		mask1.push_back(a);
		mask2.push_back(b);
	}
}
int f(int init){
	Q[size++] = init;
	memo[init] = 0;
	int good = (1<<16)-1;
	while(head < size){
		int q = Q[head++];
		int cost = memo[q];
		if(good == q) return cost;
		
		rep(i,mask1.size()){
			int bit = (q & ~mask1[i]) | mask2[i];
			if(!visi[bit]){
				visi[bit] = 1;
				memo[bit] = cost + 1;
				Q[size++] = bit;
			}
		}
	}
	

}

int main(){
	cin >> n;
	rep(i,n) cin >> h[i] >> w[i];
	rep(i,4)rep(j,4){
		char c;cin >> c;
		if(c=='R')c = 0;
		if(c=='G')c = 1;
		if(c=='B')c = 2;
		goal[i][j] = c;
	}
	
	rep(k,n){
		rep(i,7)rep(j,7){
			gen(k,i-3,j-3);
		}
	}

	
	cout << f(0) << endl;
	
	
}