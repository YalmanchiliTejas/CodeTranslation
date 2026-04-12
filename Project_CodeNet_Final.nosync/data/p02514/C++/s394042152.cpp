#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int to_i(string s){
	int n=0;
	for(int i=0 ; i < s.size() ; i++ ){
		n = n*10 + s[i]-'0';
	}
	return n;
}

int dis(pair<int,int> p , pair<int,int> p_){
	return abs(p.first-p_.first)+abs(p.second-p_.second);
}

int main(){
	int w,h;
	while( cin >> w >> h , w||h ){
		map< int , vector<pair<int,int> > > f;
		int gx,gy,t=0;
		vector< vector<int> > dp;

		for(int y=0 ; y < h ; y++ ){
			for(int x=0 ; x < w ; x++ ){
				string s;
				cin >> s;
				if( s == "S" ){
					pair<int,int> p(x,y);
					f[0].push_back( p );
				}else if( s == "G" ){
					gx = x;
					gy = y;
				}else if( s != "." ){
					int a = to_i( s );
					pair<int,int> p(x,y);
					f[a].push_back( p );
					t = max( t , a );
				}
			}
		}
		pair<int,int> p(gx,gy);
		f[t+1].push_back( p );
		for(int i=0 ; i <= t+1 ; i++ ){
			vector<int> vc;
			for(int j=0 ; j < f[i].size() ; j++ ){
				vc.push_back( 1000000 );
			}
			dp.push_back( vc );
		}
		dp[0][0] = 0;
		for(int i=0 ; i <= t ; i++ ){
			for(int j=0 ; j < f[i].size() ; j++ ){
				for(int k=0 ; k < f[i+1].size() ; k++ ){
					int d = dis( f[i][j] , f[i+1][k] );
					dp[i+1][k] = min( dp[i+1][k] , d + dp[i][j] );
				}
			}
		}
		cout << dp[t+1][0] << endl;
	}
}