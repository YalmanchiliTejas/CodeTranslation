#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>

#define INF 1001

using namespace std;

struct point{
	int x,y,z;
	point():x(0),y(0),z(0){}
	bool operator <(const point &t)const{
		if( x < t.x ){
			return true;
		}else if( x == t.x ){
			if( y < t.y ){
				return true;
			}else if( y == t.y ){
				if( z < t.z ){
					return true;
				}
			}
		}
		return false;
	}
	void rot90arndX(){ int tz = z; z = -y; y = tz; }
	void rot90arndY(){ int tz = z; z = x; x = -tz; }
	void rot90arndZ(){ int tx = x; x = y; y = -tx; }
};

struct strange_key{
	vector<point> vp;

	void rot90arndX(){
		for(unsigned int i = 0; i < vp.size(); ++i){
			vp[i].rot90arndX();
		}
	}
	void rot90arndY(){
		for(unsigned int i = 0; i < vp.size(); ++i){
			vp[i].rot90arndY();
		}
	}
	void rot90arndZ(){
		for(unsigned int i = 0; i < vp.size(); ++i){
			vp[i].rot90arndZ();
		}
	}

	bool Same(strange_key &t){
		if( vp.size() != t.vp.size() )
			return false;

		for(int a = 0; a < 4; ++a){
			for(int b = 0; b < 4; ++b){
				for(int c = 0; c < 4; ++c){
					bool bSame = true;
					sort( vp.begin(), vp.end() );
					sort( t.vp.begin(), t.vp.end() );
					
					int dx = vp[0].x - t.vp[0].x;
					int dy = vp[0].y - t.vp[0].y;
					int dz = vp[0].z - t.vp[0].z;
					
					for(unsigned int l = 1; l < vp.size() && bSame; ++l){
						if( dx != vp[l].x - t.vp[l].x )
							bSame = false;
						if( dy != vp[l].y - t.vp[l].y )
							bSame = false;
						if( dz != vp[l].z - t.vp[l].z )
							bSame = false;
					}
					if( bSame )
						return true;

					rot90arndX();
				}
				rot90arndY();
			}
			rot90arndZ();
		}
		return false;
	}
};

void input_strange_key( istream &is, int n, strange_key &in ){
	if( is ){
		point now;
		bool val[51]={false,};
		vector<point> pos_mem(51);
		
		val[0]=true;
		for(int i = 0; i < n; ++i){
			string s;
			
			cin >> s;
			if( s[0] != '+' && s[0] != '-' ){
				int mem = atoi( s.c_str() );
				if( val[ mem ] ){
					now = pos_mem[ mem ];
				}else{
					pos_mem[ mem ] = now;
					val[ mem ] = true;
				}
			}else{
				int progress = ( s[0] == '+' ? 2 : -2 );
				point next = now;
				switch( s[1] ){
					case 'x':
						now.x += progress / 2;
						in.vp.push_back( now );
						now.x += progress / 2;
						break;
					case 'y':
						now.y += progress / 2;
						in.vp.push_back( now );
						now.y += progress / 2;
						break;
					case 'z':
						now.z += progress / 2;
						in.vp.push_back( now );
						now.z += progress / 2;
						break;
				}
			}
		}
	}
}

int main(){
	while( true ){
		int n1,n2;
		strange_key a, b;

		cin>>n1;
		if( n1 == 0 )
			break;
		input_strange_key( cin, n1, a );
		cin>>n2;
		input_strange_key( cin, n2, b );

		if( a.Same( b ) )
			cout << "SAME\n";
		else
			cout << "DIFFERENT\n";

	}
	return 0;
}