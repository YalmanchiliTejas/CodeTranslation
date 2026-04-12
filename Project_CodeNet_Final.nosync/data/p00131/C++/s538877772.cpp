#include <iostream>
#include <vector>
using namespace std;

int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
vector<vector<int> > solve(vector<vector<int> > m_){
	vector<vector<int> > ans = m_;
	
	// 0..1023 ツづδ仰ーツプ, iツづ個各ツビツッツトツづ債暗ェツ氾板湘」ツづ個猟アツ子ツづ個督鳴づ陛サツづーツ表ツつキ
	for(int i=0 ; i < 1024 ; i++ ){
		vector<vector<int> > m = m_;
		int d[10][10] = {0};
		
		for(int x=0 ; x < 10 ; x++ ){
			// i ツづ警ツ氾板姪堋づ個ビツッツトツづーツ偲ヲツづィツ出ツつキ
			if( i & (1 << x) ){
				d[0][x] = 1;
				for(int j=0 ; j < 5 ; j++ ){
					int mx = x + dx[j];
					int my = 0 + dy[j];
					if( mx < 0 || my < 0 || mx >= 10 || my >= 10 ) continue;
					m[my][mx] = (m[my][mx])? 0 : 1 ;
				}
			}
		}
		
		for(int y=1 ; y < 10 ; y++ ){
			for(int x=0 ; x < 10 ; x++ ){
				if( m[y-1][x] == 1 ){
					d[y][x] = 1;
					for(int j=0 ; j < 5 ; j++ ){
						int mx = x + dx[j];
						int my = y + dy[j];
						if( mx < 0 || my < 0 || mx >= 10 || my >= 10 ) continue;
						m[my][mx] = (m[my][mx])? 0 : 1 ;
					}
				}
			}
		}
		
		bool flag = true;
		for(int y=0 ; y < 10 ; y++ ){
			for(int x=0 ; x < 10 ; x++ ){
				if( m[y][x] ){
					flag = false;
					break;
				}
			}
		}
		if( flag ){
			for(int y=0 ; y < 10 ; y++ ){
				for(int x=0 ; x < 10 ; x++ ){
					ans[y][x] = d[y][x];
				}
			}
			break;
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	for( ; n-- ; ){
		vector<vector<int> > m(10);
		
		for(int y=0 ; y < 10 ; y++ ){
			vector<int> v(10);
			m[y] = v;
			
			for(int x=0 ; x < 10 ; x++ ){
				cin >> m[y][x];
			}
		}
		vector<vector<int> > ans = solve( m );
		for(int y=0 ; y < 10 ; y++ ){
			for(int x=0 ; x < 10 ; x++ ){
				cout << ans[y][x];
				if( x != 9 ) 
					cout << " ";
			}
			cout << endl;
		}
	}
}