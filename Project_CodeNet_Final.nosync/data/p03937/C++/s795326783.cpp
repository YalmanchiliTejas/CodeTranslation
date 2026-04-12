#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    char c;
    for(int i=0;i < h;i++){
        for(int j = 0;j<w;j++){
            cin >> c;
            a[i][j] = c;
        }
    }
    int height = 0;
    int right = 0;
    for(int i=0;i<h;i++){
        for(int j =0;j<w;j++) {
            if(a[i][j] == '#'){
                if(height != i){
                    if(j < right) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                    height = i;
                }
                right = j;
            }
        }
    }
    cout << "Possible" << endl;
}