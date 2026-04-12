#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


int main(){
	int n ;
	multiset<int> se;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	
	for(int i=0;i<n;++i){
		multiset<int>::iterator it = se.lower_bound(v[i]);
		if(it== se.begin()){
			se.insert(v[i]);
		}else{
			--it;
			se.erase(it);
			se.insert(v[i]);
		}		
	}
	cout << se.size() <<endl;
	
	
	
	
	
	return 0;
}
