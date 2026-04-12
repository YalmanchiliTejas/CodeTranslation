#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int Up = 0;
const int South = 1;
const int East = 2;
const int West = 3;
const int North = 4;
const int Down = 5;

void rotate(int& a, int& b, int& c, int& d){
    swap(c, d);
    swap(b, c);
    swap(a, b);
}


int main(){
    int i, n, sum, dice[6];
    string op;
    while(cin >> n){
        if(n == 0){
            break;
        }
        for(i = 0; i < 6; ++i){
            dice[i] = i + 1;
        }
        sum = 1;
        for(i = 0; i < n; ++i){
            cin >> op;
            if(op == "North"){
                rotate(dice[Up], dice[North], dice[Down], dice[South]);
            }else if(op == "East"){
                rotate(dice[Up], dice[East], dice[Down], dice[West]);
            }else if(op == "West"){
                rotate(dice[Up], dice[West], dice[Down], dice[East]);
            }else if(op == "South"){
                rotate(dice[Up], dice[South], dice[Down], dice[North]);
            }else if(op == "Right"){
                rotate(dice[North], dice[East], dice[South], dice[West]);
            }else if(op == "Left"){
                rotate(dice[North], dice[West], dice[South], dice[East]);
            }
            sum += dice[Up];
        }
        cout << sum << endl;
    }
}