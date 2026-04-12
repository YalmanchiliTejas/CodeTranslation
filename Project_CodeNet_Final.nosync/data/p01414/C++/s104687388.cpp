#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

int main(){
	const char COLOR[] = "RGB";
	int N;
	cin >> N;
	vector<pii> stamps(N);
	for(int i = 0; i < N; ++i){ cin >> stamps[i].first >> stamps[i].second; }
	string goal;
	for(int i = 0; i < 4; ++i){
		string line;
		cin >> line;
		goal += line;
	}
	set<string> maskset;
	for(int i = 0; i < N; ++i){
		for(int y = 1 - stamps[i].first; y < 4; ++y){
			for(int x = 1 - stamps[i].second; x < 4; ++x){
				string mask = "................";
				for(int j = 0; j < stamps[i].first; ++j){
					if(y + j < 0){ continue; }
					if(y + j >= 4){ break; }
					for(int k = 0; k < stamps[i].second; ++k){
						if(x + k < 0){ continue; }
						if(x + k >= 4){ break; }
						mask[(y + j) * 4 + (x + k)] = '-';
					}
				}
				maskset.insert(mask);
			}
		}
	}
	vector<string> masks;
	masks.reserve(maskset.size());
	for(set<string>::iterator it = maskset.begin(); it != maskset.end(); ++it){
		masks.push_back(*it);
	}
	set<string> passed_front;
	stack<string> q0, q1;
	stack<string> *cur_front = &q0, *next_front = &q1;
	cur_front->push(goal);
	passed_front.insert(goal);
	int answer = 0;
	while(true){
		while(!cur_front->empty()){
			string &s = cur_front->top();
			string z;
			for(vector<string>::iterator it = masks.begin(); it != masks.end(); ++it){
				z = s;
				char c = '.';
				for(int i = 0; i < 16; ++i){
					if((*it)[i] == '.' || s[i] == '.'){ continue; }
					if(c == '.'){
						c = s[i];
					}else if(c != s[i]){
						c = '.';
						break;
					}
				}
				if(c == '.'){ continue; }
				for(int i = 0; i < 16; ++i){
					if((*it)[i] != '.'){ z[i] = '.'; }
				}
				if(passed_front.find(z) == passed_front.end()){
					if(z == "................"){
						cout << answer + 1 << endl;
						return 0;
					}
					passed_front.insert(z);
					next_front->push(z);
				}
			}
			cur_front->pop();
		}
		swap(cur_front, next_front);
		++answer;
	}
	return 0;
}