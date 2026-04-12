#include <iostream>

using namespace std;

class Dice {
    int dice[6];

public:
    Dice() {
        dice[0] = 1, dice[1] = 2, dice[2] = 3;
        dice[3] = 4, dice[4] = 5, dice[5] = 6;
    }
    int North();
    int East();
    int West();
    int South();
    int Right();
    int Left();
};

int main()
{
    int n;

    while (cin >> n, n) {
        Dice dice;

        int sum = 1;
        string op;
        for (int i = 0; i < n; ++i) {
            cin >> op;

            if (op == "North")
                sum += dice.North();
            else if (op == "East")
                sum += dice.East();
            else if (op == "West")
                sum += dice.West();
            else if (op == "South")
                sum += dice.South();
            else if (op == "Right")
                sum += dice.Right();
            else if (op == "Left")
                sum += dice.Left();
        }

        cout << sum << endl;
    }

    return 0;
}

int Dice::North()
{
    swap(dice[0], dice[4]);
    swap(dice[0], dice[1]);
    swap(dice[1], dice[5]);

    return dice[0];
}

int Dice::East()
{
    swap(dice[0], dice[2]);
    swap(dice[0], dice[5]);
    swap(dice[0], dice[3]);

    return dice[0];
}

int Dice::West()
{
    swap(dice[0], dice[3]);
    swap(dice[0], dice[2]);
    swap(dice[2], dice[5]);

    return dice[0];
}

int Dice::South()
{
    swap(dice[0], dice[1]);
    swap(dice[0], dice[5]);
    swap(dice[0], dice[4]);

    return dice[0];
}

int Dice::Right()
{
    swap(dice[1], dice[3]);
    swap(dice[1], dice[2]);
    swap(dice[2], dice[4]);

    return dice[0];
}

int Dice::Left()
{
    swap(dice[1], dice[2]);
    swap(dice[1], dice[4]);
    swap(dice[1], dice[3]);

    return dice[0];
}