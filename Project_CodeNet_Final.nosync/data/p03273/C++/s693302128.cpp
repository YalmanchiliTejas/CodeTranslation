#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int h,w;
	cin>>h>>w;
	bool a[110][110]={};
	bool r[110]={},s[110]={};
	fori(h){
		forj(w){
			char hoge;
			cin>>hoge;
			a[i][j]=(hoge=='#');
			if(a[i][j]){
				r[i]=true;s[j]=true;
			}
		}
	}

	fori(h){
		forj(w){
			if(r[i]&&s[j]){
				cout<<((a[i][j])?'#':'.');
			}

		}
		if(r[i])
			cout<<"\n";
	}
}