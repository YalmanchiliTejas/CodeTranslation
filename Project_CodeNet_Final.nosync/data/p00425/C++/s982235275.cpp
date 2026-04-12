#include <stdio.h>
#include <string.h>

class Dice {
public:
    Dice() { reset(); };
    void reset() {top = 1; front = 2; side = 3;}

    int top;
    int front;
    int side;
    int move(char op[]);
    // void show() { printf("%d %d %d\n", top, front, side); };

private:
    const int SUM = 7;
    void swap(int *a, int *b);
};

void Dice::swap(int *a, int *b) {
    int tmp = *a; 
    *a = SUM - *b;
    *b = tmp;
}

int Dice::move(char op[]) {
    if      (strcmp(op, "North") == 0 ) swap(&this->front, &this->top   );
    else if (strcmp(op, "East")  == 0 ) swap(&this->top,   &this->side  );
    else if (strcmp(op, "West")  == 0 ) swap(&this->side,  &this->top   );
    else if (strcmp(op, "South") == 0 ) swap(&this->top,   &this->front );
    else if (strcmp(op, "Right") == 0 ) swap(&this->side,  &this->front );
    else if (strcmp(op, "Left")  == 0 ) swap(&this->front, &this->side  );
    return this->top;
}

int main () {
    Dice dice;
    char op[10];
    int n, sum;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        sum = 1;
        dice.reset();
        while(n--) {
            scanf("%s", op);
            // printf("%s: ", op); dice.move(); dice.show();
            sum += dice.move(op);
        }
        printf("%d\n", sum);
    }

    return 0;
}