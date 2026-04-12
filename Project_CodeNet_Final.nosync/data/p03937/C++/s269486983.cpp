#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int curw=0;
    bool flag=true;
    for(int h=0; h<H; h++) {
        string str;
        cin >> str;
        char pre;
        for(int w=0; w<W; w++) {
            if(curw>w) {
                if(str[w]=='#') {
                    flag=false;
                    break;
                }
            } else if(curw==w) {
                if(str[w]!='#') {
                    flag=false;
                    break;
                } else {
                    pre='#';
                }
            } else {
                if(pre=='#' && str[w]=='#') {
                    curw++;
                } else if(str[w]!='#') {
                    pre='.';
                } else {
                    flag=false;
                    break;
                }
            }
        }
    }
    
    if(flag) {
        cout << "Possible"  << endl;
    } else {
        cout << "Impossible" << endl;
    }
    

    return 0;
    
}