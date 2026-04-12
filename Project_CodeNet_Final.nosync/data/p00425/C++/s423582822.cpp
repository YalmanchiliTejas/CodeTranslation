#include <bits/stdc++.h>
using namespace std;

class Dice
{
private :
    int top;
    int under;
    int right;
    int left;
    int front;
    int back;
public :
    Dice (int x, int y, int z) {
        top = x;
        under = 7 - x;
        front = y;
        back = 7 - y;
        left = z;
        right = 7 - z;
    }

    void South ();
    void North ();
    void West ();
    void East ();
    void Right ();
    void Left ();
    int Top ();
};

void Dice::South () {
    int tmp = top;
    top = back;
    back = under;
    under = front;
    front = tmp;
}

void Dice::North () {
    int tmp = top;
    top = front;
    front = under;
    under = back;
    back = tmp;
}

void Dice::East () {
    int tmp = top;
    top = right;
    right = under;
    under = left;
    left = tmp;
}

void Dice::West () {
    int tmp  = top;
    top = left;
    left = under;
    under = right;
    right = tmp;
}

void Dice::Right () {
    int tmp = front;
    front = left;
    left = back;
    back = right;
    right = tmp;
}

void Dice::Left () {
    int tmp = front;
    front = right;
    right = back;
    back = left;
    left = tmp;
}

int Dice::Top () {
    return top;
}

int main ()
{
    int n;
    while(cin >> n, n) {
        Dice dice(1,2,3);
        int sum = 1;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            if (str == "North") dice.North();
            else if (str == "South") dice.South();
            else if (str == "East") dice.East();
            else if (str == "West") dice.West();
            else if (str == "Left") dice.Left();
            else dice.Right();

            sum += dice.Top();
        }

        cout << sum << endl;
    }

    return 0;
}