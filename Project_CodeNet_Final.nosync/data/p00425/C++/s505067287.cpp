#include<cstdio>
#include<iostream>
#include<string>

void North(void);
void South(void);
void West(void);
void East(void);
void Right(void);
void Left(void);
void Init(void);

using namespace std;

int DiceTop = 1;
int DiceBottom = 6;
int DiceWest = 4;
int DiceEast = 3;
int DiceSouth = 2;
int DiceNorth = 5;
int DiceSum = 1;

int main(void)
{
    int n;
    string str;

    while (1){
        scanf("%d", &n);

        if (n == 0){
            break;
        }

        for (int i = 0;i < n;i++){
      
            cin >> str;

            if (str == "North"){
                North();
            }
            else if (str == "South"){
                South();
            }
            else if (str == "West"){
                West();
            }
            else if (str == "East"){
                East();
            }
            else if (str == "Right"){
                Right();
            }
            else if (str == "Left"){
                Left();
            }
        }
        printf("%d\n", DiceSum);
        Init();
    }
 
    return 0;
}

void North(void)
{
    int tmp;

    tmp = DiceTop;
    DiceTop = DiceSouth;
    DiceSouth = DiceBottom;
    DiceBottom = DiceNorth;
    DiceNorth = tmp;

    DiceSum += DiceTop;
}

void South(void)
{
    int tmp;

    tmp = DiceTop;
    DiceTop = DiceNorth;
    DiceNorth = DiceBottom;
    DiceBottom = DiceSouth;
    DiceSouth = tmp;

    DiceSum += DiceTop;
}

void West(void)
{
    int tmp;

    tmp = DiceTop;
    DiceTop = DiceEast;
    DiceEast = DiceBottom;
    DiceBottom = DiceWest;
    DiceWest = tmp;

    DiceSum += DiceTop;
}

void East(void)
{
    int tmp;

    tmp = DiceTop;
    DiceTop = DiceWest;
    DiceWest = DiceBottom;
    DiceBottom = DiceEast;
    DiceEast = tmp;

    DiceSum += DiceTop;
}

void Right(void)
{
    int tmp;

    tmp = DiceSouth;
    DiceSouth = DiceEast;
    DiceEast = DiceNorth;
    DiceNorth = DiceWest;
    DiceWest = tmp;

    DiceSum += DiceTop;
}

void Left(void)
{
    int tmp;

    tmp = DiceSouth;
    DiceSouth = DiceWest;
    DiceWest = DiceNorth;
    DiceNorth = DiceEast;
    DiceEast = tmp;

    DiceSum += DiceTop;
}

void Init(void)
{
    DiceTop = 1;
    DiceBottom = 6;
    DiceWest = 4;
    DiceEast =3;
    DiceSouth = 2;
    DiceNorth = 5;
    DiceSum = 1;
}