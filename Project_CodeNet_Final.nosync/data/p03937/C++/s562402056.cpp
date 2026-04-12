#include <iostream>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int count = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin >> c;
            if(c=='#') count++;
        }
    }
    if(count == h+w-1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
