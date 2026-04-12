#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
	int id;
	int num;
};

bool comp(data d1, data d2){
	if(d1.num > d2.num){
		return true;
	}else{
		return false;
	}
}

int main(){
	data d;
	char c;
	int n;
	vector<data> vd;
	while(cin >> d.id >> c >> d.num){
		if(d.id == 0 && d.num == 0) break;
		vd.push_back(d);
	}
	sort(vd.begin(), vd.end(), comp);
	while(cin >> n){
		int count = 1;
		int a = vd[0].num;
		vector<data>::iterator iter = vd.begin();
		while((*iter).id != n){
			if((*iter).num != a){
				count++;
				a = (*iter).num;
			}
			iter++;
		}
		if((*iter).num != a){
			count++;
		}
		cout << count << endl;
	}
	return 0;
}