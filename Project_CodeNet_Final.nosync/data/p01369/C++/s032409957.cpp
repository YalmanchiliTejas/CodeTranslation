#include <iostream>
#include <map>
#define rep(i,N) for(int i = 0; i < (int)(N); i++)
using namespace std;

int main(){
        string str1 = "qazwsxedcrfvtgb";
        string str2 = "yhnujmikolp";

        map<char,bool> left;
        map<char,bool> right;
        rep(i,str1.size()) left[str1[i]]=true;
        rep(i,str2.size()) right[str2[i]]=true;
        char lr[32];

        string input;
        while(true) {
                cin >> input;
                if(input == "#") break;
                int ans = 0;
                rep(i, input.size()){
                        if(left[input[i]] == true) {
                                lr[i] =  'l';
                        }else if (right[input[i]] == true) {
                                lr[i] =  'r';
                        }
                        if(i != 0 && lr[i-1] != lr[i]) {
                                ans++;
                        }
                }
                cout << ans << endl;
        }

        return 0;
}

