#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>


#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;


int main(void){

int bg,tn;
char k;
map <int,int> bgtn;
vector<int> tns;
	while(cin >> bg >> k >> tn){
		if( cin.eof() || (bg == 0 && tn == 0) ) break;
		tns.push_back(tn);
		bgtn[bg] = tn;
	}
	
	sort(tns.begin(),tns.end(),greater<int>());
	tns.erase(unique(tns.begin(), tns.end()), tns.end());

	while(cin >> bg){
		if( cin.eof()  ) break;
		rep(i,tns.size()) if(bgtn[bg] == tns[i]) {
				cout << i+1  <<endl;
				break;
			}
	}
	return 0;
	
	
}