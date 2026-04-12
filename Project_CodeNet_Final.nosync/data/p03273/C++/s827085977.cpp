#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }
    vector<string> temp;
    for (int i = 0; i < h; ++i) {
        bool flag = true;
        for (int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == '#')
            {
                flag = false;
            }
        }
        if(!flag)
        {
            temp.push_back(grid[i]);
        }
    }
    vector<string> temp2(temp.size(), "");
    for (int i = 0; i < w; ++i) {
        bool flag = true;
        for (int j = 0; j < temp.size(); ++j) {
            if(temp[j][i] == '#')
            {
                flag = false;
            }
        }
        if(!flag)
        {
            for (int j = 0; j < temp.size(); ++j) {
                temp2[j].push_back(temp[j][i]);
            }
        }
    }
    for (int i = 0; i < temp2.size(); ++i) {
        cout << temp2[i] << endl;
    }
    return 0;
}
