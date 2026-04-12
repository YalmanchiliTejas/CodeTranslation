#include <iostream>
using namespace std;

bool isRight(char c){
    // string left  = "qwertasdfgzxcvb";
    string right = "yuiophjklnm";
    for(int i=0;i<int(right.size());i++){
        if(right[i] == c){
            return true;
        }
    }

    return false;
}

int main(){

    while(true){
        string s;
        cin >> s;
        if(s == "#"){
            break;
        }

        int count = 0;

        if(s.size() == 0){
            cout << 0 << endl;
            continue;
        }

        bool nowRight = isRight(s[0]);

        for(int i=0;i<int(s.size());i++){
            if((isRight(s[i]) && !nowRight) || (!isRight(s[i]) && nowRight)){
                count++;
            }
            nowRight = isRight(s[i]);
        }

        cout << count << endl;
    }

    return 0;
}