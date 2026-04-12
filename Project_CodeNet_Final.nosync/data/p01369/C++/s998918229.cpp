#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;

char left_s[15]={'q', 'a', 'z', 'w', 's', 'x', 'e', 'd', 'c', 'r', 'f', 'v', 't', 'g', 'b'};
char right_s[11]={'y', 'h', 'n', 'u', 'j', 'm', 'i', 'k', 'o', 'l', 'p'};
int main() {
    string str;
    while(cin >> str, str!="#"){
        int n = str.size();
        int flag=-1, cnt=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<15; ++j){
                if(str[i]==left_s[j]){
                    if(i>0&&flag == 1){
                        cnt++;
                    }
                    flag = 0;
                }
            }
            for(int j=0; j<11; ++j){
                if(str[i]==right_s[j]){
                    if(i>0&&flag == 0){
                        cnt++;
                    }
                    flag = 1;
                }
            }

        }
        cout << cnt << endl;
    }
    return 0;
}
