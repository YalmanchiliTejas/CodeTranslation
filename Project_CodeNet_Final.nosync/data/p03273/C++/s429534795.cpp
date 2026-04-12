#include <iostream>
#include <vector>
#include <numeric>
#include <list>
using namespace std;

// それぞれの行と列において、全て白（"."）だったら表示しないで詰める
// （AtCoder公式の答えより）黒が含まれている列と行は出力される
int main() {
    int height, width;
    cin >> height >> width;
    
    vector<vector<char> > table(height, vector<char>(width));

    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.at(0).size(); j++)
        {
            cin >> table.at(i).at(j);
        }
    }

    vector<bool> containsBlackCellInTheRow(height, false), containsBlackCellInTheColumn(width, false);

    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.at(0).size(); j++)
        {
            if(table.at(i).at(j) == '#')
            {
                containsBlackCellInTheRow.at(i) = true;
                containsBlackCellInTheColumn.at(j) = true;
            }
        }
    }

    for (int i = 0; i < table.size() ; i++)
    {
        if(containsBlackCellInTheRow.at(i))
        {
            for (int j = 0; j < table.at(0).size(); j++)
            {
                if(containsBlackCellInTheColumn.at(j))
                    cout << table.at(i).at(j);
            }
            cout << endl;
        }
    }
    
}