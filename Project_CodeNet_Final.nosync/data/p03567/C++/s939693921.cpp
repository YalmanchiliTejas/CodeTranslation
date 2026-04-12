#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < s.length();i++){
        if(i!=0){
            if(s[i]=='C'&&s[i-1]=='A')
                flag = true;
        }
    }
    if(flag)
        cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
}