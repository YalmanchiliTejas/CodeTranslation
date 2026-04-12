#include<iostream>

int main(void)
{
	int A, B, C;	//ピザの値段
	int X, Y;

	int X_rest = 0;
	int Y_rest = 0;	// X 枚のAピザと Y 枚のBピザを用意する
	
	int result = 0;

	// 入力
	std::cin >> A >> B >> C >> X >> Y;

	int A_min = (A < C*2) ? A : C*2;
	int B_min = (B < C*2) ? B : C*2;

	//1. 同時買いの話
	if(X > Y){
		// AピザがBピザより多い

		//1. 同時買いの条件
		if(A+B >= 2*C){
			result += 2*C*Y;
		}else{
			//2. 同時買いはできません。
			result += (A+B)*Y;
		}
		// 残り
		X_rest = X - Y;

		result += X_rest * A_min;

	}else if(X < Y){
		// BピザがAピザより多い

		//1. 同時買いの条件
		if(A+B >= 2*C){
			result += 2*C*X;
		}else{
			//2. 同時買いはできません。
			result += (A+B)*X;
		}
		// 残り
		Y_rest = Y - X;

		result += Y_rest * B_min;

	}else{
	// AピザとBピザの枚数が同じとき

		//1. 同時買いの条件
		if(A+B >= 2*C){
			result = 2*C*X;
		}else{
			//2. 同時買いはできません。
			result = A*X + B*Y;
		}
		// 残りはありません
	}

	std::cout << result << std::endl;

	return 0;
}