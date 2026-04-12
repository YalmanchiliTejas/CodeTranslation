#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin >> s;
    int suma = 0;
    int sumb = 0;
    for(int i = 0; i < 3;i++)
    {
        if(s[i] == 'A') suma++;
        else sumb++;
    }
    if(suma == 0 || sumb == 0)
    {
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}
