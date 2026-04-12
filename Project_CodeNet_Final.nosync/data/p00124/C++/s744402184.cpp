#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <sstream>

#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;

typedef pair<int,string> mypair;

int main(void){

int n, k, m, h;
mypair ch[10];
bool kg=false;
	while(cin >>n){
		if(n==0 || cin.eof()) break;
		rep(i,n){
			cin >> ch[i].second;
			cin >> k >> m >> h;
			ch[i].first = (k *3 + h *1) * 100 + 50- i;
		}
		sort(ch, ch+n, greater<mypair>());
		if(kg) cout << endl;
		kg=true;
		rep(i,n) cout << ch[i].second << "," << (int)(ch[i].first/100) << endl;
		
	}
	return 0;
	
}