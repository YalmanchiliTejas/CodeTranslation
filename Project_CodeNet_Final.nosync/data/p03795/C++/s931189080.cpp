//インクルード
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

//型宣言
typedef long long ll;
typedef unsigned long long ull;
typedef std::string string;
typedef ll answerType;

//変数宣言
ll N;
answerType answer;

//関数のプロトタイプ宣言
//入力の取得
void getInput();
//答えを求める
answerType calcAnswer();

//メイン関数
int main() {
	//入力の取得
	getInput();

	//答え
	answerType answer = calcAnswer();

	//答えの出力
	std::cout << answer << std::endl;

	//正常終了
	return EXIT_SUCCESS;
}

//入力の取得
void getInput() {
	std::cin >> N;
}

//答えを求める
answerType calcAnswer() {
	ll temp = N * 800;
	ll temp2 = N / 15;
	ll temp3 = temp2 * 200;
	return temp - temp3;
}
