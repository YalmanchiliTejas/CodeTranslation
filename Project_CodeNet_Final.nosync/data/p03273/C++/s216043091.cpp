#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x, y;
    
    cin >> x >> y;
    vector<string> data(x);
    vector<int> a(x, 0);
    vector<int> b(y, 0);
    int i = -1, j;
    while (++i < x)
    {
        cin >> data.at(i);
        j = -1;
        while (++j < y)
            data.at(i).at(j) == '.' ? a[i]++, b[j]++ : 0;
    }
    i = -1;
    while (++i < x)
    {
        if (a[i] == y)
            continue;
        j = -1;
        while (++j < y)
        {
            if (b[j] == x)
                continue;
            cout << data.at(i).at(j);
        }
        cout << endl;
    }
}
