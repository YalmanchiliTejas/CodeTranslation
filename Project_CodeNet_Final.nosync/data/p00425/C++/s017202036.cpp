//Dice
#include <iostream>
#include <string>

using namespace std;

enum Order{
	North,
	East,
	West,
	South,
	Right,
	Left
};

class Dice{
private:
	enum Side{
		Top_ = 0,
		Bottom_,
		Flont_,
		Right_,
		Back_,
		Left_
	};
	int side[6];
public:
	void Init();
	int Move(Order ord);
};

int main(){
	Dice dice;
	int ordNum;
	int total;
	string loader;
	Order ord;

	while (1){
		//初期化
		dice.Init();
		total = 1;
		//代入+計算
		cin >> ordNum;
		if (ordNum == 0)break;
		for (int i = 0; i < ordNum; ++i){
			cin >> loader;
			if (loader == "North")ord = North;
			if (loader == "East")ord = East;
			if (loader == "West")ord = West;
			if (loader == "South")ord = South;
			if (loader == "Right")ord = Right;
			if (loader == "Left")ord = Left;
			total += dice.Move(ord);
		}
		cout << total << endl;
	}
	return 0;
}

void Dice::Init(){
	side[Top_] = 1;
	side[Bottom_] = 6;
	side[Flont_] = 2;
	side[Right_] = 3;
	side[Back_] = 5;
	side[Left_] = 4;
}

int Dice::Move(Order ord){
	int t;
	switch (ord){
	case North:
		t = side[Top_];
		side[Top_] = side[Flont_];
		side[Flont_] = side[Bottom_];
		side[Bottom_] = side[Back_];
		side[Back_] = t;
		break;
	case East:
		t = side[Top_];
		side[Top_] = side[Left_];
		side[Left_] = side[Bottom_];
		side[Bottom_] = side[Right_];
		side[Right_] = t;
		break;
	case West:
		t = side[Top_];
		side[Top_] = side[Right_];
		side[Right_] = side[Bottom_];
		side[Bottom_] = side[Left_];
		side[Left_] = t;
		break;
	case South:
		t = side[Top_];
		side[Top_] = side[Back_];
		side[Back_] = side[Bottom_];
		side[Bottom_] = side[Flont_];
		side[Flont_] = t;
		break;
	case Right:
		t = side[Flont_];
		side[Flont_] = side[Right_];
		side[Right_] = side[Back_];
		side[Back_] = side[Left_];
		side[Left_] = t;
		break;
	case Left:
		t = side[Flont_];
		side[Flont_] = side[Left_];
		side[Left_] = side[Back_];
		side[Back_] = side[Right_];
		side[Right_] = t;
		break;
	default:
		break;
	}
	return side[Top_];
};