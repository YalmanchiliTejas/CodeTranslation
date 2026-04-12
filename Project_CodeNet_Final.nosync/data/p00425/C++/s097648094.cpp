#include <iostream>
#include <string>

using namespace std;

void North();
void East();
void West();
void South();
void Right();
void Left();

int up, down, north, south, east, west;
int ans;

int main(){
    string s;
    int n;
    
    while(cin >> n, n){
        ans = 1;
        up = 1, down = 6, north = 5, south = 2, east = 3, west = 4;
        for (int i = 0; i < n; i++){
            cin >> s;

            if (s == "North"){
                North();
            } else if (s == "East"){
                East();
            } else if (s == "West"){
                West();
            } else if (s == "South"){
                South();
            } else if (s == "Right") {
                Right();
            } else if (s == "Left") {
                Left();
            }
            ans += up;
        }
        cout << ans << endl;
    }
}

void North(){
    int temp;
    temp = up;
    up = south;
    south = down;
    down = north;
    north = temp;
}

void East(){
    int temp;
    temp = up;
    up = west;
    west = down;
    down = east;
    east = temp;
}

void West(){
    int temp;
    temp = up;
    up = east;
    east = down;
    down = west;
    west = temp;
}

void South(){
    int temp;
    temp = up;
    up = north;
    north = down;
    down = south;
    south = temp;
}

void Right(){
    int temp;
    temp = south;
    south = east;
    east = north;
    north = west;
    west = temp;
}

void Left(){
    int temp;
    temp = south;
    south = west;
    west = north;
    north = east;
    east = temp;
}