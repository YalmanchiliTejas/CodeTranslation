#include <iostream>
using namespace std;

typedef struct {
    int top;
    int forward;
    int right;
} diceMap;

int main(){
    while (1){
    string str;
    diceMap dice;
    dice.top = 1;
    dice.forward = 2;
    dice.right = 3;
    
    int n;
    cin >> n;
    if (n == 0) break;
    int score = 1;

    for (int m = 0; m < n; m++){
	cin >> str;
	diceMap bufDice = dice;

	if (str == "North"){
	    bufDice.top = dice.forward;
	    bufDice.forward = 7 - dice.top;
	    bufDice.right = dice.right;
	}
	else if (str == "East"){
	    bufDice.top = 7 - dice.right;
	    bufDice.forward = dice.forward;
	    bufDice.right = dice.top;
	}
	else if (str == "South"){
	    bufDice.top = 7 - dice.forward;
	    bufDice.forward = dice.top;
	    bufDice.right = dice.right;
	}
	else if (str == "West"){
	    bufDice.top = dice.right;
	    bufDice.forward = dice.forward;
	    bufDice.right = 7- dice.top;
	}
	else if (str == "Right"){
	    bufDice.top = dice.top;
	    bufDice.forward = dice.right;
	    bufDice.right = 7 - dice.forward;
	}
	else if (str == "Left"){
	    bufDice.top = dice.top;
	    bufDice.forward = 7- dice.right;
	    bufDice.right = dice.forward;
	}
	dice = bufDice;
	score += bufDice.top;
    }
    cout << score << endl;
    }
}