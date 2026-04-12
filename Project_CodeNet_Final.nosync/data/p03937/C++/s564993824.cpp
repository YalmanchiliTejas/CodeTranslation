#include <iostream>
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	string a[h];
	for(int i = 0; i < h; i++) cin >> a[i];
	for(int i = 0; i + 1 < h; i++) for(int j = 0; j + 1 < w; j++) if((a[i + 1][j] == '#' && a[i + 1][j + 1] == '#' && a[i][j + 1] == '#') || (a[i][j] == '#' && a[i + 1][j] == '#' && a[i][j + 1] == '#')){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
}