#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int Z;
    //-----------
    int n;
    //vector<string> strs;
    string instr;
    int tmpcount[26] = {0};
    int count[26] = {0};
    int init = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> instr;

        //個数のカウント
        for (int j = 0; j < instr.size(); j++)
        {
            //cout << instr[j] << endl;
            tmpcount[(int)instr[j] - 97] += 1;
        }

        //countに反映
        if (init == 0) //初回だけコピー
        {
            for (int j = 0; j < 26; j++)
            {
                count[j] = tmpcount[j]; //そのまま代入する
                tmpcount[j] = 0;        //tmpの初期化
            }
            init = 1;
        }
        else //初回以降は比較．個数が異なれば，少ない方を代入する
        {
            for (int j = 0; j < 26; j++)
            {
                if (count[j] != tmpcount[j])
                    count[j] = min(count[j], tmpcount[j]);

                tmpcount[j] = 0; //tmpの初期化
            }
        }
        //ここでループ
    }

    //出力のパート
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                cout << (char)(97 + i);
            }
        }
    }

    cout << endl;

    //cout << "Hello,World" << endl;

    //-----------
    cin >> Z;
    return 0;
}