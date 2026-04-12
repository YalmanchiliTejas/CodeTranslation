#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#include<cassert>
#include<functional>

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int hight;
	int width;
	int counter = 0;
	std::string current_str;//その時見ている行
	std::string current_str2;


	//入力
	std::cin >> hight >> width;
	std::vector<std::string> input(hight);
	for (int i = 0; i < hight; i++){
		std::cin >> input[i];
	}

	//行の消去
	for (int i = 0; i < hight; i++){
		current_str = input[i];//見ている行を更新
		counter = 0;//counter初期化

		for (int j = 0; j < width; j++){
			if (current_str[j] == '.'){
				counter++;
			}
		}

		if (counter == width){//input[i]が全部'.'だったら
			for (int k = i; k < hight - 1; k++){//今見ている行以降を更新（移動）
				input[k] = input[k + 1];
			}
			hight--;//高さを減らす
			i--;//移動したからもう一度同じ行を見る
		}
	}

	//列の消去
	for (int i = 0; i < width; i++){
		current_str = input[0];//1行目で'.'のある列のみ調べればよい
		counter = 0;

		if (current_str[i] == '.'){
			counter++;
			for (int j = 1; j < hight; j++){
				current_str2 = input[j];
				if (current_str2[i] == '.'){
					counter++;
				}
			}
		}

		if (counter == hight){//i列目がすべて'.'のとき
			for (int j = 0; j < hight; j++){
				current_str2 = input[j];//行を取出し
				for (int k = i; k < width - 1; k++){
					current_str2[k] = current_str2[k + 1];//移動
				}
				input[j] = current_str2;//更新（元に戻す）
			}

			width--;
			i--;
		}
	}

	for (int i = 0; i < hight; i++){
		current_str = input[i];
		for (int j = 0; j < width; j++){
			std::cout << current_str[j];
		}
		std::cout << '\n';
	}

	return 0;
}