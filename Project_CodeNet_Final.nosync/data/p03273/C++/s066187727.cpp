#include<iostream>
using namespace std;

int main(){
	int H, W, ansH, ansW;
	bool changeFlag = false;
	cin >> H >> W;
	ansH = H;
	ansW = W;

	char **array = new char*[H];

	for(int height = 0; height < H; height++){
		array[height] = new char[W];
		for(int width = 0; width < W; width++){
			cin >> array[height][width];
		}
	}

	do{
		changeFlag = false;
		for(int height = 0; height < H; height++){
			bool blankFlag = true;
			for(int width = 0; width < W; width++){
				if(array[height][width] != '.')
					blankFlag = false;
			}

			if(blankFlag && height < ansH-1){
				for(int width = 0; width < W; width++){
					array[height][width] = array[height+1][width];
					array[height+1][width] = '.';
				}
				changeFlag = true;
			}else if(blankFlag && height == ansH-1){
				changeFlag = true;
			}
		}
		if(changeFlag)
			ansH--;
	}while(changeFlag);

	do{
		changeFlag = false;
		for(int width = 0; width < W; width++){
			bool blankFlag = true;
			for(int height = 0; height < ansH; height++){
				if(array[height][width] != '.')
					blankFlag = false;
			}

			if(blankFlag && width < ansW-1){
				for(int height = 0; height < ansH; height++){
					array[height][width] = array[height][width+1];
					array[height][width+1] = '.';
				}
				changeFlag = true;
			}else if(blankFlag && width == ansW-1){
				changeFlag = true;
			}
		}
		if(changeFlag) ansW--;
	}while(changeFlag);

	for(int height = 0; height < ansH; height++){
		for(int width = 0; width < ansW; width++){
			cout << array[height][width];
		}
		cout << '\n';

		delete[] array[height];
	}
	delete[] array;

	return 0;
}