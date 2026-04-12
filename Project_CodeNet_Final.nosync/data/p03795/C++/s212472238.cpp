#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x = 0;
    int y = 0;
    int bonus = 200;
    int c = 0;

    int n;

    cin >> n;

    for(int i = 0;i < n; i++){
        x += 800;
        c ++;
        if(c%15==0){
            y += bonus;
        }
    }

    cout << x-y << endl;
}