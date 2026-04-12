#include <iostream>
#include <string>

void turnNorth(int *d){
    int one = d[0];
    d[0] = d[1];
    d[1] = d[5];
    d[5] = d[4];
    d[4] = one;
}

void turnEast(int *d){
    int one = d[0];
    d[0] = d[3];
    d[3] = d[5];
    d[5] = d[2];
    d[2] = one;
}

void turnWest(int *d){
    int one = d[0];
    d[0] = d[2];
    d[2] = d[5];
    d[5] = d[3];
    d[3] = one;
}

void turnSouth(int *d){
    int one = d[0];
    d[0] = d[4];
    d[4] = d[5];
    d[5] = d[1];
    d[1] = one;
}

void turnRight(int *d){
    int two = d[1];
    d[1] = d[2];
    d[2] = d[4];
    d[4] = d[3];
    d[3] = two;
}

void turnLeft(int *d){
    int two = d[1];
    d[1] = d[3];
    d[3] = d[4];
    d[4] = d[2];
    d[2] = two;
}

void resetDice(int *d){
    for(int i=0; i<6; i++){
        d[i] = i + 1;
    }
}

int main(){
    int dice[6] = {1, 2, 3, 4, 5, 6};
    int n, ans;
    std::string rot;

    while(std::cin >> n){
        if(!n){
            break;
        }
        ans = 1;
        resetDice(dice);
        while(n--){
            std::cin >> rot;
            if(rot == "North"){
                turnNorth(dice);
            }
            else if(rot == "East"){
                turnEast(dice);
            }
            else if(rot == "West"){
                turnWest(dice);
            }
            else if(rot == "South"){
                turnSouth(dice);
            }
            else if(rot == "Right"){
                turnRight(dice);
            }
            else if(rot == "Left"){
                turnLeft(dice);
            }
            ans += dice[0];
        }
        std::cout << ans << std::endl;
    }

    return 0;
}