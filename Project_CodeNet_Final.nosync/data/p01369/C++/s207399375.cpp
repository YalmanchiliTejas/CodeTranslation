#include <iostream>
#include <map>
using namespace std;

int main(){
    map<char,bool> keymap; //ツ右ツづ可淞つキツづ「ツづつつセツつッtrueツづ可つキツづゥboolツ連ツ想ツ配ツ療ア
    for(char i='a'; i<='z'; i++){
        keymap[i] = false;
    }

    keymap['y'] = true;
    keymap['h'] = true;
    keymap['n'] = true;
    keymap['u'] = true;
    keymap['j'] = true;
    keymap['m'] = true;
    keymap['i'] = true;
    keymap['k'] = true;
    keymap['o'] = true;
    keymap['l'] = true;
    keymap['p'] = true;

    string str;

    while(cin >> str){
        if(str == "#") break;
        bool pre = keymap[str.at(0)];
        int cnt = 0;
        for(int i=1; i<str.size(); i++){
            if(pre xor keymap[str.at(i)]){
                cnt++;
            }
            pre = keymap[str.at(i)];
        }
        cout << cnt << endl;
    }
    return 0;
}