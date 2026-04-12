#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct State{
	int lx, ly, rx, ry;
	State(int lx_, int ly_, int rx_, int ry_){
		lx = lx_; ly = ly_; rx = rx_; ry = ry_;
	}
};

const int INF = 1e+8;
bool stamp[4][4][4][4] = {0};
vector<State> v;
char C[5][5];
int d[1<<16];
char color[3] = {'R','G','B'};


void init(){
	for(int ly=0 ; ly < 4 ; ly++ ){
		for(int lx=0 ; lx < 4 ; lx++ ){
			for(int ry=0 ; ry < 4 ; ry++ ){
				for(int rx=0 ; rx < 4 ; rx++ ){
					stamp[ly][lx][ry][rx] = false;
				}
			}
		}
	}
}

void check_stamp(int w, int h){
	for(int dy = -3 ; dy <= 3 ; dy++ ){
		for(int dx = -3 ; dx <= 3 ; dx++ ){
			int lx=4, ly=4, rx=-1, ry=-1;
			for(int y = dy ; y < dy + h ; y++ ){
				for(int x = dx ; x < dx + w ; x++ ){
					if( x < 0 || y < 0 || 4 <= x || 4 <= y ) continue;
					lx = min(lx, x);
					ly = min(ly, y);
					rx = max(rx, x);
					ry = max(ry, y);
				}
			}
			
			if( lx < 0 || 4 <= lx || ly < 0 || 4 <= ly ) continue;
			if( rx < 0 || 4 <= rx || ry < 0 || 4 <= ry ) continue;
			stamp[ly][lx][ry][rx] = true;
		}
	}
}

int solve(){
	for(int i=0 ; i < (1<<16) ; i++ ){
		d[i] = INF;
	}
	d[0] = 0;
	queue<int> q;
	q.push( 0 );
	
	int res = INF;
	while( !q.empty() ){
		int bits = q.front();
		int cost = d[bits];
		q.pop();
		
		if( bits == (1<<16)-1 ){
			res = cost;
			break;
		}
		for(int i=0 ; i < v.size() ; i++ ){
			for(int j=0 ; j < 3 ; j++ ){
				int next = bits;
				for(int y=0 ; y < 4 ; y++ ){
					for(int x=0 ; x < 4 ; x++ ){
						if( v[i].ly <= y && y <= v[i].ry && v[i].lx <= x && x <= v[i].rx ){
							if( next & (1<<(y*4+x)) ){ // テヲツュツ」テ」ツ?療」ツ??」ツ?ィテ」ツ?禿」ツつ催」ツ?ォティツ可イjテ」ツつ津・ツ。ツ療」ツつ?
								if( color[j] != C[y][x] ){ // 1 => 0
									next = next & ~(1<<(y*4+x));
								}
							}else{ // テヲツュツ」テ」ツ?療」ツ?湘・ツ。ツ療」ツつ古」ツ?ヲテ」ツ??」ツ?ェテ」ツ??」ツ?ィテ」ツ?禿」ツつ催」ツ?ォテ・ツ。ツ療」ツつ?
								if( color[j] == C[y][x] ){ // 0 => 1
									next = next | (1<<(y*4+x));
								}
							}
						}
					}
				}
				if( d[next] == INF ){
					d[next] = cost + 1;
					q.push(next);
				}
			}
		}
	}
	return res;
}

void make_stamp(){
	// テ」ツつケテ」ツつソテ」ツδウテ」ツδ療」ツ?ョテ・ツ。ツ療」ツつ甘ヲツ鳴ケテ」ツ?ョテ」ツδ?」ツつァテ」ツδε」ツつッ (テ・ツ、ツ堙」ツ?湘」ツ?ヲテ」ツつ?00テゥツ?堙」ツつ?
	for(int ly=0 ; ly < 4 ; ly++ ){
		for(int lx=0 ; lx < 4 ; lx++ ){
			for(int ry = ly ; ry < 4 ; ry++ ){
				for(int rx = lx ; rx < 4 ; rx++ ){
					if( stamp[ly][lx][ry][rx] ){
						if( lx < 0 || 4 <= lx || ly < 0 || 4 <= ly ) continue;
						if( rx < 0 || 4 <= rx || ry < 0 || 4 <= ry ) continue;
						v.push_back( State(lx,ly,rx,ry) );
					}
				}
			}
		}
	}
}

int main(){
	init();
	
	int N;
	cin >> N;
	for(int i=0 ; i < N ; i++ ){
		int h, w;
		cin >> h >> w;
		check_stamp(w, h);
	}
	for(int y=0 ; y < 4 ; y++ ){
		cin >> C[y];
	}
	make_stamp();
	
	int ans = solve();
	cout << ans << endl;
}