#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

multiset < int > s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a;
	set < int >::const_iterator it;
	for(int i=0; i<n; i++){
		cin >> a;
		if(!s.empty()){
			it=s.lower_bound(a);
			if(it==s.end()){
				it--;
			}
			while(it!=s.begin() && *it>=a){
				it--;
			}
//			cout << "manji " <<  *it << endl;
			if(*it<a){
//				cout <<"naso " << *it << endl;
				s.erase(it);
			}
		}
		s.insert(a);
	}
	cout << s.size() << '\n';
	return 0;
}