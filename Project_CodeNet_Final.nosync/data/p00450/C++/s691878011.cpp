#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class stone{
public:
	int place;
	// white:0,black:1
	int color;

	stone(int _place,int _color){
		place = _place;
		color = _color;
	}
	stone();
};

int main(){

	int n;
	while(cin >> n && n != 0){
		stack<stone> ss;
		for(int i = 0; i < n; i++){
			int t;
			cin >> t;
			if(ss.size() == 0){
				ss.push(stone(1,t));
			}
			else{
				stone s = ss.top();
				// ツつィツつュツつセツつッ
				if(i % 2==0){
					if(s.color == t){
						ss.pop();
						ss.push(stone(s.place+1,t));
					}
					else{
						ss.push(stone(s.place+1,t));
					}
				}
				// ツ板スツ転ツ渉按猟敖づつゥ
				else{
					if(s.color == t){
						ss.pop();
						ss.push(stone(s.place+1,t));
					}
					else{
						ss.pop();
						if(ss.size() == 0)
							ss.push(stone(s.place+1,t));
						else{
							ss.pop();
							ss.push(stone(s.place+1,t));
						}
					}
				}
			}
		}

		int cnt = 0;
		int prv = 0;
		bool flag = false;
		while(ss.size()){
			stone tmp = ss.top();
			if(tmp.color == 0){
				prv = tmp.place;
				ss.pop();
				if(ss.size() == 0){
					cnt += prv;
					break;
				}
				else{
					stone sto = ss.top();
				//	ss.pop();
					cnt += (prv - sto.place);
					prv = sto.place;
				}
			}
			else{
			//	prv = tmp.place;
				ss.pop();
				if(ss.size() != 0){
					prv = ss.top().place;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}