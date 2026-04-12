#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N;

vector<int> mem;
vector<int> mas;


int w[16];
int h[16];
int a[4][4];

int memo[1<<16];

int main(){
	for(int i = 0 ; i < (1<<16) ; i++) memo[i] = -1;
	int N;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> w[i];
		cin >> h[i];
	}
	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0 ; j < 4 ; j++){
			char c;
			cin >> c;
			if( c == 'R') a[i][j] = 0;
			if( c == 'G') a[i][j] = 1;
			if( c == 'B') a[i][j] = 2;
		}
		
	for(int i = 0 ; i < N ; i++){
		for(int c = 0 ; c < 3 ; c++){
			for(int j = -4 ; j < 4 ; j++){
				for(int k = -4 ; k < 4 ; k++){
					int mask = 0;
					int res = 0;
					for(int l = 0 ; l < h[i] ; l++){
						for(int m = 0 ; m < w[i] ; m++){
							int tx = j + l;
							int ty = k + m;
							if( tx < 0 || tx >= 4 || ty >= 4 || ty < 0 ) continue;
							mask |= 1 << (ty * 4 + tx);
							res  |= ( a[ty][tx] == c ) << (ty * 4 + tx );
							
						}
					}
					mem.push_back(res);
					mas.push_back(mask);
				}		
			}
		}
	}
	queue<int> Q;
	
	Q.push(0);
	while(Q.size()){
		int q = Q.front(); Q.pop();
		for(int i = 0 ; i < mas.size() ; i++){
			int next = q & ~mas[i];
			next |= mem[i];
			if( memo[next] == -1){
				memo[next] = memo[q]+1;
				Q.push(next);
			}
		}
	}
	cout << memo[(1<<16)-1] << endl;
}