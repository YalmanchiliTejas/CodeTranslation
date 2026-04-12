#include <iostream>
#include <set>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    char a[h][w] = {};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }
    
    set<int> x,y;
    for(int i=0; i<h; i++){
        bool clean = true;
        for(int j=0; j<w; j++){
            if(a[i][j] == '#'){
                clean = false;
                break;
            }
        }
        if(clean) x.insert(i);
    }
    for(int j=0; j<w; j++){
        bool clean = true;
        for(int i=0; i<h; i++){
            if(a[i][j] == '#'){
                clean = false;
                break;
            }
        }
        if(clean) y.insert(j);
    }
    int col = w - y.size();
    for(int i=0; i<h; i++){
        int cy = 0;
        for(int j=0; j<w; j++){
            if(x.count(i) == 0 && y.count(j) == 0){
                cy++;
                cout << a[i][j];
                if(cy == col) cout << "\n";
            }
        }
    }
    
    return 0;
}