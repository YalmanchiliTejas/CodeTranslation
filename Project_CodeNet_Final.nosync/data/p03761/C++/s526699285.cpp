#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n;
    cin >> n;
    vector<string> S(n);
    vector<vector<int>> alphCount(26, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        string inStr;
        cin >> inStr;

        for(int j = 0; j < inStr.size(); j++){
            alphCount[inStr[j]-97][i]++;
        }
    }

    vector<int> minCount(26, 0);
    string outStr = "";
    for(int i = 0; i < 26; i++){
        minCount[i] = *min_element(alphCount[i].begin(), alphCount[i].end());
        for(int k = 0; k < minCount[i]; k++){
            outStr += (char) (i+97);
        }
    }

    cout << outStr << endl;
    
    return 0;
}
