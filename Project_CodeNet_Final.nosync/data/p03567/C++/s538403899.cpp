#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
#include <functional>
#include <map>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
    string s;
    cin >> s;

    bool flag = false;
    for (int i = 0; i < 4; i++){
        if (s[i] == 'A'&&s[i + 1] == 'C'){
            flag = true;
        }
    }

    if (flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}