#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	while( cin >> n , n ){
		vector<int> v;
		
		for(int i=0 ; i < n ; i++ ){
			int a;
			cin >> a;
			a = (a == 0)? 1 : -1 ;
			if( i == 0 ){
				v.push_back( a );
			}else if( i%2 && ((v[v.size()-1] < 0 && a > 0) || (v[v.size()-1] > 0 && a < 0)) ){
				if( v.size() >= 2 ){
					int t = v[v.size()-1];
					v.pop_back();
					v[v.size()-1] += -t + a;
				}else{
					v[v.size()-1] *= -1;
					v[v.size()-1] += a;
				}
			}else{
				if( (v[v.size()-1] > 0 && a > 0) || (v[v.size()-1] < 0 && a < 0) ){
					v[v.size()-1] += a;
				}else{
					v.push_back( a );
				}
			}
		}
		int ans = 0;
		for(int i=0 ; i < v.size() ; i++ ){
			if( v[i] > 0 )
				ans += v[i];
		}
		cout << ans << endl;
	}
}