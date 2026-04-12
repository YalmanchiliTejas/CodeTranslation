#include <bits/stdc++.h>
using namespace std;

int main() {

int H, W;
bool check, check2 = false;
cin >> H >> W;
vector<vector<char>> input(H, vector<char>(W));
for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
        cin >> input.at(i).at(j);
    }
}

for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
        if (input.at(i).at(j) == '#'){
            check = true;
        }
    }
    if (check == false){
        for (int k = 0; k < W; k++){
            input.at(i).at(k) = ' ';
        }
    }
    else{
        check = false;
    }
}

check = false;
for (int i = 0; i < W; i++){
    for (int j = 0; j < H; j++){
        if(input.at(j).at(i) == '#'){
            check = true;
        }
    }
    if(check == false){
        for (int k = 0; k < H; k++){
            input.at(k).at(i) = ' ';
        }
    }
    else{
        check = false;
    }
}

for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
        if(input.at(i).at(j) != ' '){
            cout << input.at(i).at(j);
        }
    }
    for (int k = 0; k < W; k++){
        if(input.at(i).at(k) != ' '){
            check2 = true;
        }
    }
    if(check2 == true){
        check2 = false;
        cout << endl;
    }
    else{
        continue;
    }
}

}