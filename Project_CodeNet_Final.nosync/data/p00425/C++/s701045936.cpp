#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Dice {
    //top, front, left, right, back, bottom
public :
    int face[6];

    Dice(int _face[]) {
        for(int i = 0; i < 6; i++)
            face[i] = _face[i];
    };
    
    void roll(int a, int b, int c, int d) 
    {
        int t = face[d];
        face[d] = face[c];
        face[c] = face[b];
        face[b] = face[a];
        face[a] = t;
    }

    void rollX()
    {
        roll(0, 1, 5, 4);
    }

    void rollY()
    {
        roll(0, 3, 5, 2);
    }

    void rollZ()
    {
        roll(1, 3, 4, 2);
    }

    Dice** rollAll()
    {
        Dice *dices[24];
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 4; j++) {
                dices[i * 4 + j] = new Dice(face);
                rollZ();
            }
            if((i & 1) > 0) rollX();
            else rollY();
        }
        return dices;
    }
};

int main()
{
    int n, face[] = {1, 2, 4, 3, 5, 6};
    while(cin >> n && n) {
        Dice dice(face);
        int sum = 0;
        string op;
        for(int i = 0; i < n; i++) {
            cin >> op;
            if(op == "North") {
                for(int k = 0; k < 3; k++)
                    dice.rollX();
            } else if(op == "East") {
                dice.rollY();
            } else if(op == "West") {
                for(int k = 0; k < 3; k++)
                    dice.rollY();
            } else if(op == "South") {
                dice.rollX();
            } else if(op == "Right") {
                for(int k = 0; k < 3; k++)
                    dice.rollZ();
            } else {
                dice.rollZ();
            }
            sum += dice.face[0];
        }
        cout << sum + 1 << endl;
        
    }
}