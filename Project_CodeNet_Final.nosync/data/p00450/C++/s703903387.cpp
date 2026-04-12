#include<iostream>
#include<vector>
using namespace std;
struct Mables{int num, color;};

int main(){
	for(;;){
		int n;
		vector<Mables> va;
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			if(i == 0){
				va.push_back((Mables){1, a});
				continue;
			}
			if(va.back().color == a){
				va.back().num++;
			}else{
				if(i % 2 == 0){
					va.push_back((Mables){1, a});
				}else{
					if(va.size() == 1){
						va.back().color = a;
						va.back().num++;
					}
					else{
						va[va.size() - 2].num += va[va.size() - 1].num + 1;
						va.pop_back();
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < va.size(); i++){
			if(va[i].color == 0) ans += va[i].num;
		}
		cout << ans << endl;
	}
	return 0;
}

