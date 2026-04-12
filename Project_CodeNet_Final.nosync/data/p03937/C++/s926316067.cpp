#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int h, w;
vector<string> v;

int main(){
	scanf("%d %d", &h, &w);
	for(int i=0; i<h; ++i){
		char t[10];
		scanf("%s", t);
		v.push_back(t);
	}
	int x = 0;
	for(int i=0; i<h; ++i){
		while(x <= w && v[i][x] == '#'){
			v[i][x] = '.';
			++x;
		}
		--x;
	}
	bool f = true;
	for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
			if(v[i][j] == '#')
				f = false;
	if(f) printf("Possible\n");
	else printf("Impossible\n");
}