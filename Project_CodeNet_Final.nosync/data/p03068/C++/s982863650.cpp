#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    vector<char>s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }
    cin >> k;
    char con = s.at(k - 1);
    //cout << con << endl;
    for (int i = 0; i < n; i++) {
        if (s.at(i) != con) {
            s.at(i) = '*';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s.at(i);
    }
    cout << endl;
}
