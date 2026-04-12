#include <iostream>
using namespace std;

int h,w;
bool a[110][110];
int main()
{
	cin >> h >> w;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			char tmp;
			cin >> tmp;
			a[i][j] = (tmp == '#') ? true : false;
		}
	}

	bool hf[110],wf[110];
	for(int i = 0;i < 110;i++){
		hf[i] = false;
		wf[i] = false;
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			hf[i] |= a[i][j];
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			wf[i] |= a[j][i];
		}
	}

	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(hf[i] && wf[j]){
				cout << ((a[i][j])? "#" : ".");
			}
		}
		if(hf[i] || i == h-1)cout << endl;
	}
}