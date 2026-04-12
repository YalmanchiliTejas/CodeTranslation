#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct sec{
	int from;
	int to;
};

typedef pair<sec, int> P;

int main(){
	
	int n;
	
	vector<P> v;
	
	while(true){
		
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		int num;
		P p1;
		
		cin >> num;
		
		p1.first.from = 0;
		p1.first.to = 0;
		p1.second = num;
		v.push_back(p1);
		
		for(int i = 1; i < n; i++){
			cin >> num;
			if(v.at(v.size() - 1).second == num){
				v.at(v.size() - 1).first.to = i;
			}else if(i % 2 == 0){
				p1.first.from = i;
				p1.first.to = i;
				p1.second = num;
				v.push_back(p1);
			}else{
				if(v.size() > 1){
					v.at(v.size() - 2).first.to = i;
					v.pop_back();
				}else{
					v.at(v.size() - 1).first.to = i;
					v.at(v.size() - 1).second = num;
				}
			}
		}
		
		int ans = 0;
		
		for(int i = 0; i < v.size(); i++){
			if(v.at(i).second == 0){
				ans += v.at(i).first.to - v.at(i).first.from + 1;
			}
		}
		
		printf("%d\n", ans);
		
		v.erase(v.begin(), v.end());
	}
	return 0;
}