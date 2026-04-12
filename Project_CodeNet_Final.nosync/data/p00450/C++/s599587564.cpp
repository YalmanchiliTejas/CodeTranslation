#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> P;

int main(){
	int n;
	while( cin >> n , n ){
		vector<P> v;
		for(int i=0 ; i < n ; i++ ){
			int c;
			cin >> c;
			
			int k = v.size() - 1;
			if( i % 2 == 0 ){ // テ」ツ?イテ」ツ?」テ」ツ?湘」ツつ甘ィツソツ氾」ツ?陛」ツ?ェテ」ツ??
				if( v.empty() ){
					v.push_back( P(c, 1) );
				}else if( v[k].first == c ){
					v[k].second++;
				}else{
					v.push_back( P(c, 1) );
				}
			}else{ 
				if( v[k].first == c ){
					v[k].second++;
				}else{ // テ」ツ?イテ」ツ?」テ」ツ?湘」ツつ甘ィツソツ氾」ツ??
					if( v.size() >= 2 ){
						int m = v[k].second + 1;
						v.pop_back();
						k = v.size() - 1;
						v[k].second += m;
					}else{
						v[k].first = c;
						v[k].second++;
					}
				}
			}
		}
		int ans = 0;
		for(int i=0 ; i < v.size() ; i++ ){
			if( v[i].first == 0 ) ans += v[i].second;
		}
		cout << ans << endl;
	}
}