#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int H,W;
    cin >> H >> W;
    int count = 0;
    for(int i=0;i<H;i++){
        string str;
        cin >> str;
        for(int j=0;j<W;j++){
            if(str[j] == '#')count++;
        }
    }
    if(count == H + W - 1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
} 