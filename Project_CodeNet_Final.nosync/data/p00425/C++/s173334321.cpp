#include <iostream>
using namespace std;
int dice[6];
int dice2[6];
void shokika(){
    dice[0] = 1;
    dice[1] = 2;
    dice[2] = 3;
    dice[3] = 5;
    dice[4] = 4;
    dice[5] = 6;
}
void copy(){
    for(int i = 0;i < 6;i++){
        dice2[i] = dice[i];
    }

}
void north(){
    copy();
    dice[0] = dice2[1];
    dice[1] = dice2[5];
    dice[5] = dice2[3];
    dice[3] = dice2[0];
}
void south(){
    copy();
    dice[0] = dice2[3];
    dice[1] = dice2[0];
    dice[5] = dice2[1];
    dice[3] = dice2[5];
}
void east(){
    copy();
    dice[0] = dice2[4];
    dice[2] = dice2[0];
    dice[5] = dice2[2];
    dice[4] = dice2[5];
}
void west(){
    copy();
    dice[0] = dice2[2];
    dice[2] = dice2[5];
    dice[5] = dice2[4];
    dice[4] = dice2[0];
}
void right(){
    copy();
    dice[1] = dice2[2];
    dice[2] = dice2[3];
    dice[3] = dice2[4];
    dice[4] = dice2[1];
}
void left(){
    copy();
    dice[1] = dice2[4];
    dice[2] = dice2[1];
    dice[3] = dice2[2];
    dice[4] = dice2[3];
}

int main(){
    int a[5];
    int k = 0;
    while(1){
        a[k] = 1;
        int n;
        cin >> n;
        if(n == 0)break;
        shokika();
        for(int i = 0;i < n;i++){
            string g;
            cin >> g;
            if(g == "North")north();
            if(g == "South")south();
            if(g == "West")west();
            if(g == "East")east();
            if(g == "Right")right();
            if(g == "Left")left();
            a[k] += dice[0];
        }
        k++;
    }
    for(int i= 0;i < k;i++){
        cout << a[i] <<endl;
    }
    return 0;
}
