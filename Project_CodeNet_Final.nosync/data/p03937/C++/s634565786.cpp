#include<iostream>
#include<set>

using namespace std;

int main(){
	set<int> vis;
	int h, w;
	cin >>h >>w;
	for(int r = 0; r < h; ++r){
		for(int c = 0; c < w; ++c){
			char v;
			cin >>v;
			if(v == '#'){
				vis.insert(r*w+c);
			}
		}
	}
	
	int dest = (h - 1) * w + w - 1;
	int steps = h + w - 2;
	int mx_mask = (1 << steps) - 1;
	
	bool poss = false;
	for(int msk = 0; msk < mx_mask; ++msk){
		int r = 0, c = 0;
		bool bad = false;
		set<int> cur_vis{0};
		for(int stp = 0; stp < steps; ++stp){
			if(msk & (1 << stp)){
				++r;
			}
			else{
				++c;
			}
			int loc = r * w + c;
			if(vis.find(loc) == end(vis)){
				bad = true;
			}
			cur_vis.insert(loc);
		}
		int fin = r * w + c;
		if(fin == dest && !bad && vis.size() == cur_vis.size())
			poss = true;
	}
	if(poss)
		cout <<"Possible\n";
	else
		cout <<"Impossible\n";
	
	return 0;
}
