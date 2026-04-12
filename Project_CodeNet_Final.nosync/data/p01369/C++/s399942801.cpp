#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <numeric>

using namespace std;

char left_[16] = "qwertasdfgzxcvb";
char right_[12] = "yuiophjklnm";

int main(){
    char str[33] = {'\0'};
    while(cin >> str, strcmp(str,"#")){
        int l = 0, r = 0;
        int ll = 0, rr = 0;
        int cnt = 0;
        for(int i=0; i<strlen(str); i++){
            for(int j=0; j<15; j++){
                if(str[i] == left_[j]){
                    r=0;
                    l++;
                    break;
                }
            }
            for(int j=0; j<11; j++){
                if(str[i] == right_[j]){
                    l=0;
                    r++;
                    break;
                }
            }
            if(((ll-rr<0)&&(l-r>0)) || ((rr-ll<0)&&(r-l>0))){
                cnt++;
            }
            ll = l; rr = r;
        }
        cout << cnt << endl;
        for(int i=0; i<32; i++) str[i] = '\0';
    }
    return 0;
}

