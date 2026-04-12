#include <stdio.h>
#define A 0
#define B 1
#define S 2
#define E 3
#define N 4
#define W 5

class Dice{
private:
    int num[6]; // ^ v o > x <
public:
    Dice(){
        num[A] = 1;
        num[B] = 6;
        num[S] = 2;
        num[E] = 3;
        num[N] = 5;
        num[W] = 4;
    }
    void North(){
        int tmp=num[A];
        num[A]=num[S];
        num[S]=num[B];
        num[B]=num[N];
        num[N]=tmp;
    }
    void East(){
        int tmp=num[A];
        num[A]=num[W];
        num[W]=num[B];
        num[B]=num[E];
        num[E]=tmp;
    }
    void West(){
        int tmp=num[A];
        num[A]=num[E];
        num[E]=num[B];
        num[B]=num[W];
        num[W]=tmp;
    }
    void South(){
        int tmp=num[A];
        num[A]=num[N];
        num[N]=num[B];
        num[B]=num[S];
        num[S]=tmp;
    }
    void Right(){
        int tmp=num[S];
        num[S]=num[E];
        num[E]=num[N];
        num[N]=num[W];
        num[W]=tmp;
    }
    void Left(){
        int tmp=num[S];
        num[S]=num[W];
        num[W]=num[N];
        num[N]=num[E];
        num[E]=tmp;
    }
    int GetAbove(){return num[0];}
};

int main(void){
    int n;
    char buf[8];
    int sum;
    Dice *dice;
    
    while (scanf("%d",&n), n!=0){
        sum=1;
        dice = new Dice;
        for (int i=0; i<n; i++){
            scanf("%s", buf);
            switch(buf[0]){
                case 'N': dice->North(); break;
                case 'E': dice->East(); break;
                case 'W': dice->West(); break;
                case 'S': dice->South(); break;
                case 'R': dice->Right(); break;
                case 'L': dice->Left(); break;
            }
            sum += dice->GetAbove();
        }
        printf("%d\n", sum);
        delete dice;
    }
}