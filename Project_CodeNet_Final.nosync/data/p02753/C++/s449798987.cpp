#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int arr[2] = {0};
    for(int i=0;i<3;i++)
        arr[s[i]-'A'] = 1;
    if(arr[0] == 1 && arr[1] == 1)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}