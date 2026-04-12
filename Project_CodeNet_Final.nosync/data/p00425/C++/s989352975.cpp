#include <iostream>
#include <map>
#include <string>
using namespace std;
//north, west, south, east
int dice[7][4] = {
    {},
    {2, 4, 5, 3},
    {6, 4, 1, 3},
    {5, 6, 2, 1},
    {5, 1, 2, 6},
    {1, 4, 6, 3},
    {5, 4, 2, 3}
};
int vals[7] = {0, 6, 5, 4, 3, 2, 1};

map<string, int> createmap() {
    map<string, int> m;
    m.insert({"North", 0});
    m.insert({"West", 1});
    m.insert({"South", 2});
    m.insert({"East", 3});
    return m;
}
static map<string, int> dirs = createmap();
int dir, pos, currNum, prevNum, prevPos, sum;

void setDir(int pp) {

    int optPos = 0;
    for (int i = 0; i < 4; i++) {
        if (dice[currNum][i]== prevNum) {
            optPos = i;
            break;
        }
    }
    int res = 0;
    if (optPos != pp) {
        while (optPos != pp) {
            pp = (pp + 1) % 4;
            res++;
        }
    }
    dir = res;
}

int main() {
    int n;
    for (; ;) {
        cin >> n;
        if (n == 0) break;
        dir = 0, currNum = 6, sum=1;
        prevNum = 2, prevPos = 0;
        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            if (str == "Left") {
                sum += vals[currNum];
                dir = (dir + 3) % 4;

            }
            else if (str == "Right") {
                sum += vals[currNum];
                dir = (dir + 1) % 4;
            }
            else {
                pos = (dir + dirs[str]) % 4;
                prevNum = currNum;
                currNum = dice[currNum][pos];
                prevPos = (dirs[str]+2)%4;
                sum += vals[currNum];
                setDir(prevPos);
            }
        }
        cout << sum << endl;
    }
    return 0;
}

