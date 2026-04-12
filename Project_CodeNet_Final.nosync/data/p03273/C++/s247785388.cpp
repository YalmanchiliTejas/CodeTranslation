#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int h, w, white;
	char c;
	bool wb[100][100];
	int notout[100] = {0};
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		white = 0;
		for(int j = 0; j < w; j++){
			cin >> c;
			wb[i][j] = (c == '.' ? 1 : 0);
			white += wb[i][j];
			notout[j] += wb[i][j];
		}
		if(white == w){
			i -= 1;
			h -= 1;
			for(int j = 0; j < w; j++){
				notout[j] -= 1;
			}
		}
	}
	for(int i = 0; i < h; i++){
		
		for(int j = 0; j < w; j++){
			if(notout[j] != h) cout << (wb[i][j] == 1 ? '.' : '#') << flush;
		}
		cout << endl;
	}
	return 0;
}