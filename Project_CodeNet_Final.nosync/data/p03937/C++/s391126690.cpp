#include <iostream>
using namespace std;

int main() {
    int H, W, cnt=0; cin >> H >> W;
    for(int i=0;i<H;i++){
    	for(int j=0;j<W;j++){
            char x; cin >> x;
            if(x=='#') cnt++;
    	} 
    }
    cout << (cnt==H+W-1?"Possible":"Impossible") << endl;
    return 0;
}