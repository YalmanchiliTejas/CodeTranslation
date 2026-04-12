#include <iostream>
#include <map>
#include <functional>
using namespace std;

int main(){
	multimap<int, int, greater<int> > rank;
	while(1){
		int n, score;
		scanf("%d,%d", &n, &score);
		if(!n && !score) break;
		rank.insert( pair<int, int>(score, n) );
	}
	multimap<int, int, greater<int> >::iterator it = rank.begin();

	map<int, int> res;
	int buf = (*it).first;
	res.insert( pair<int, int>((*it).second, 1));
	it++;

	int i = 1;
	
	while(it != rank.end()){
		if(buf == (*it).first){
			res.insert( pair<int, int>((*it).second, i) );
		}else{
			res.insert( pair<int, int>((*it).second, ++i) );
			buf = (*it).first;
		}
		it++;
	}

	int group;
	while(cin >> group){
		cout << res[group] << endl;
	}
}