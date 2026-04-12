#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Team{
public:
	string name;
	int point;
	int pos;
	
	bool operator <(const Team arg) const{
		if(point > arg.point){
			return true;
		}else if(point < arg.point){
			return false;
		}else{
			if(pos < arg.pos){
				return true;
			}else{
				return false;
			}
		}
	}
};

int main(void){
	int n;
	vector<Team> v;
	Team t;
	bool first = true;
	
	while(cin >> n && n){
		string str;
		int w,l,d;
		
		if(!first) cout << endl;
		
		for(int i=0;i<n;i++){
			cin >> str >> w >> l >> d;
			t.name = str;
			t.point = w*3+d;
			t.pos = i;
			v.push_back(t);
		}
	
		sort(v.begin(),v.end());
		
		for(int i=0;i<n;i++){
			cout << v[i].name << "," << v[i].point << endl;
		}
		first = false;
		v.clear();
	}
}