#include <iostream>
#include <string>
#include <queue>

using namespace std;

int markpower[128];
int numpower[128];

int main()
{
    for (char c = '0'; c <= '9'; c++) {
        numpower[c] = c - '0';
    }
    numpower['T'] = 10;
    numpower['J'] = 11;
    numpower['Q'] = 12;
    numpower['K'] = 13;
    numpower['A'] = 14;
    char trump;
    while (cin >> trump, trump != '#') {
        string input[4][13];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                cin >> input[i][j];
            }
        }
        int win = 3;
        int ns = 0, ew = 0;
        for (int j = 0; j < 13; j++) {
            priority_queue<pair<int, int>> que;
            for (int i = 0; i < 4; i++) {
                fill_n((int *)markpower, 128, 0);
                markpower[input[win][j][1]] = 100;
                markpower[trump] = 200;
                int power = markpower[input[i][j][1]]+numpower[input[i][j][0]];
                que.push({power, i});
            }
            win = que.top().second;
            if (win % 2 == 0) ns++;
            else ew++;
        }
        if (ns > ew)
            cout << "NS " << ns % 6 << endl;
        else
            cout << "EW " << ew % 6 << endl;
    }
    return 0;
}