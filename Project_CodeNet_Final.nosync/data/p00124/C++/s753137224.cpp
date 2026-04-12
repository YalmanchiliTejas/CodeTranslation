#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	bool flag = false;

	while( cin >> n , n ){
		vector<int> vc;
		map<int,vector<string> > f;
		if( flag ){
			cout << endl;
		}else{
			flag = true;
		}

		for(int i=0 ; i < n ; i++ ){
			string name;
			int a,b,c;

			cin >> name >> a >> b >> c;
			int p = -(a*3 + c);
			if( count(vc.begin(),vc.end(),p) == 0 ){
				vc.push_back( p );
			}
			f[p].push_back( name );
		}
		sort( vc.begin() , vc.end() );
		for(int i=0 ; i < vc.size() ; i++ ){
			for(int j=0 ; j < f[vc[i]].size() ; j++ ){
				cout << f[vc[i]][j] << "," << -vc[i] << endl;
			}
		}
	}
}