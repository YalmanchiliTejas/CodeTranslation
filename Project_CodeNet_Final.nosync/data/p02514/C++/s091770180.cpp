#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;

int dis( P p , P p_ ){
	return abs(p.first-p_.first)+abs(p.second-p_.second);
}

int to_i(string s){
	int n=0;
	for(int i=0 ; i < s.size() ; i++ ){
		n = n*10 + s[i]-'0';
	}
	return n;
}

int main(){
	int w,h;
	while( cin >> w >> h , w||h ){
		string s;
		map<int,vector<P> > f;
		vector< vector<int> > dp;
		int gx,gy,t=0;

		for(int y=0 ; y < h ; y++ ){
			for(int x=0 ; x < w ; x++ ){
				cin >> s;
				if( s == "S" ){
					vector<int> vc;
					vc.push_back( 0 );
					dp.push_back( vc );
					P p(x,y);
					f[0].push_back( p );
				}else if( s == "G" ){
					gx = x;
					gy = y;
				}else if( s != "." ){
					int n = to_i(s);
					t = max( t , n );
					P p(x,y);
					f[n].push_back( p );
				}
			}
		}
		P p(gx,gy);
		f[t+1].push_back( p );
		for(int i=1 ; i <= t+1 ; i++ ){
			vector<int> vc;
			for(int j=0 ; j < f[i].size() ; j++ ){
				vc.push_back( 1000000 );
			}
			dp.push_back( vc );
		}
		for(int i=0 ; i <= t ; i++ ){
			for(int j=0 ; j < f[i].size() ; j++ ){
				for(int k=0 ; k < f[i+1].size() ; k++ ){
					int d = dis( f[i+1][k] , f[i][j] );
					dp[i+1][k] = min( dp[i+1][k] , dp[i][j]+d );
				}
			}
		}
		cout << dp[t+1][0] << endl;
	}
}