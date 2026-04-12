#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    int w,h,sharp = 0;
    cin >> w >> h;
    
    for(int i = 0; i < w*h; i++){
        char c;
        cin >> c;
        if( c == '#') sharp++;
    }
    
    if(w + h -1 == sharp){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    
}
