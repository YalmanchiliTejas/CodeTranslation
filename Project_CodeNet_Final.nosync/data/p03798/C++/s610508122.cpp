#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {

    cin >> n >> s;

    char first,second;

    char my_set[4][2] = {{'S','S'},{'W','S'},{'S','W'},{'W','W'}};

    for(int loop=0; loop<4; loop++){

        string ans = "";

        first = my_set[loop][0];
        second = my_set[loop][1];

        ans.push_back(first);
        ans.push_back(second);

        for(int i=1; i<s.size(); i++){

            if(second == 'S') {

                if (s[i] == 'o') {
                    ans.push_back(first);
                    second = first;
                    first = 'S';
                } else {//x
                    if (first == 'S') {
                        ans.push_back('W');
                        first = second;
                        second = 'W';
                    } else {
                        ans.push_back('S');
                        first = second;
                        second = 'S';
                    }
                }
            }
            else{
                if (s[i] == 'x') {
                    ans.push_back(first);
                    second = first;
                    first = 'W';
                } else {//o
                    if (first == 'S') {
                        ans.push_back('W');
                        first = second;
                        second = 'W';
                    } else {
                        ans.push_back('S');
                        first = second;
                        second = 'S';
                    }
                }
            }

        }

        if(ans[ans.size()-1] != ans[0]){
            continue;
        }

        ans.erase(ans.end()-1);

        if(my_set[loop][0] == 'S') {

            if (s[0] == 'o' && first == my_set[loop][1]) {
                cout << ans << endl;
                return 0;
            } else if (s[0] == 'x' && first != my_set[loop][1]) {
                cout << ans << endl;
                return 0;
            }
        }
        else{
            if (s[0] == 'x' && first == my_set[loop][1]) {
                cout << ans << endl;
                return 0;
            } else if (s[0] == 'o' && first != my_set[loop][1]) {
                cout << ans << endl;
                return 0;
            }
        }

    }

    cout << -1 << endl;

    return 0;
}