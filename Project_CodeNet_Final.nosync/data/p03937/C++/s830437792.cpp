#include <iostream>

using namespace std;

int main()
{
    int h, w, n;
    n = 0;
    cin >> h >> w;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            if(c == '#'){
                n++;
            }
        }
    }

    if(n == h - 1 + w){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }


    return 0;
}
