#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    cin >> str;

    vector<int> num(2);
    for (int i = 0; i < str.length(); i++)
        if (str[i] == 'A')
            num[0]++;
        else
            num[1]++;

    if (num[0] && num[1])
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}
