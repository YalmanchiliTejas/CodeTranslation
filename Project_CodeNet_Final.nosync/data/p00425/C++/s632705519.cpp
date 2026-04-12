#include <iostream>
#include <string>

using namespace std;

class Dice{
public:
    Dice() : top(1), south(2), east(3){}
    int get_top(){return top;}

    void to_north(){int temp = top; top = south; south = 7 - temp;}
    void to_south(){int temp = south; south = top; top = 7 - temp;}
    void to_west(){int temp = top; top = east; east = 7 - temp;}
    void to_east(){int temp = east; east = top; top = 7 - temp;}
    void turn_right(){int temp = south; south = east; east = 7 - temp;}
    void turn_left(){int temp = east; east = south; south = 7 - temp;}
private:
    int top;
    int south;
    int east;
};

int main()
{
    int loop;
    while(cin >> loop && loop != 0)
    {
        Dice dice;
        int sum = 1;
        string command;
        for(int i = 0; i < loop; ++i)
        {
            cin >> command;
            if(command == "South")
                dice.to_south();
            else if(command == "North")
                dice.to_north();
            else if(command == "East")
                dice.to_east();
            else if(command == "West")
                dice.to_west();
            else if(command == "Right")
                dice.turn_right();
            else if(command == "Left")
                dice.turn_left();
            sum += dice.get_top();
        }
        cout << sum << endl;
    }
}