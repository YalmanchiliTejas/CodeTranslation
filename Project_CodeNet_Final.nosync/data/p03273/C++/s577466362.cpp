#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    vector<vector<string>> data;
    vector<bool> AryY(S);

    for (int i = 0; i < S; i++)
    {
        AryY.at(i) = false;
    }
    
    for (int i = 0; i < N; i++)
    {
        vector<string> A(S);
        bool flg = false;
        string str;
        cin >> str;
        for (int j = 0; j < S; j++){
            if (str[j] == '#') {
                flg = true;
                AryY.at(j) = true;
            }
            A.at(j) = str[j];
        }
        if (flg) data.push_back(A);
    }

    for (int i = AryY.size() - 1; i >= 0; i--)
    {
        if (!AryY.at(i)) {
            for (int j = 0; j < data.size(); j++)
            {
                data.at(j).erase(data.at(j).begin()+i);
            }
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.at(i).size(); j++)
        {
            cout << data.at(i).at(j);
        }
        cout << endl;
    }
}
