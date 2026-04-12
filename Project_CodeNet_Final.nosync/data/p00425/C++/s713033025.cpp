#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Dice {
public:
    map<string, int> pos;

    Dice() {
        Dice::pos = {{"Top", 1}, {"North", 5}, {"East", 3}, {"South", 2}, {"West", 4}, {"Bottom", 6}};
    };

    int top() {
        return pos["Top"];
    }

    void rotate(const vector<string> &v) {
        int tmp = pos[v[0]];
        for (int i=0; i<(int)v.size() - 1; ++i) pos[v[i]] = pos[v[i + 1]];
        pos[v[(int)v.size() - 1]] = tmp;
    }

    void go(string di) {
        if (di == "North") rotate({"Top", "South", "Bottom", "North"});
        else if (di == "East") rotate({"Top", "West", "Bottom", "East"});
        else if (di == "West") rotate({"Top", "East", "Bottom", "West"});
        else if (di == "South") rotate({"Top", "North", "Bottom", "South"});
        else if (di == "Right") rotate({"South", "East", "North", "West"});
        else if (di == "Left") rotate({"South", "West", "North", "East"});
    }
};

int main() {
    int n;
    string di;
    while (cin >> n && n != 0) {
        auto dice = Dice();
        int sum = 1;
        while (n --) {
            cin >> di;
            dice.go(di);
            sum += dice.top();
        }
        cout << sum << endl;
    }
    return 0;
}