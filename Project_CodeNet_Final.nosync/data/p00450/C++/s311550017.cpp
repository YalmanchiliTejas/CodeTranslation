#include <vector>
#include <iostream>
using namespace std;

int main(){
	int n, c;
	for(; cin >> n, n; ){
		vector<int> v;
		v.push_back(0);
		for( int i = 1; i <= n; ++i ){
			cin >> c;
			if( v.size() % 2 != c ){
				v.back() = i;
			}
			else{
				if( i % 2 ){
					v.push_back(i);
				}
				else{
					v.pop_back();
					if( v.empty() ){
						v.push_back(0);
						v.push_back(i);
					}
					else{
						v.back() = i;
					}
				}
			}
		}

		n = v.front();
		for( int i = 2; i < v.size(); i += 2 ){
			n += v[i] - v[i-1];
		}
		cout << n << endl;
	}
}