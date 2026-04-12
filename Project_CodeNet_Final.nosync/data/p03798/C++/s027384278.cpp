#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
char answer[100001];
int result[100001];
int flag = 0;
void circulateAnimals () {
    
    if (result[0] == 1) {
        if (answer[0] == 'o') {
            result[1] = result[n - 1];
        }
        else {
            result[1] = -result[n - 1];
        }
    }
    else {
        if (answer[0] == 'x') {
            result[1] = result[n - 1];
        }
        else {
            result[1] = -result[n - 1];
        }
    }
    
    
    for (int i = 1; i < n - 2; i++) {
        if (result[i] == 1) {
            if (answer[i] == 'o') {
                result[i + 1] = result[i - 1];
            }
            else {
                result[i + 1] = -result[i - 1];
            }
        }
        else {
            if (answer[i] == 'x') {
                result[i + 1] = result[i - 1];
            }
            else {
                result[i + 1] = -result[i - 1];
            }
        }
    }
}

void check () {
    if (result[n - 2] == 1) {
        if (answer[n - 2] == 'o') {
            if (result[n - 3] == result[n - 1])
                flag++;
        }
        else {
            if (result[n - 3] != result[n - 1])
                flag++;
        }
    }
    else {
        if (answer[n - 2] == 'x') {
            if (result[n - 3] == result[n - 1])
                flag++;
        }
        else {
            if (result[n - 3] != result[n - 1])
                flag++;
        }
    }
    
    if (result[n - 1] == 1) {
        if (answer[n - 1] == 'o') {
            if (result[n - 2] == result[0])
                flag++;
        }
        else {
            //printf("re");
            if (result[n - 2] != result[0])
                flag++;
        }
    }
    else {
        if (answer[n - 1] == 'x') {
            if (result[n - 2] == result[0])
                flag++;
        }
        else {
            if (result[n - 2] != result[0])
                flag++;
        }
    }
}

void printResult () {
    if (flag < 2)
        return;
    for (int i = 0; i < n; i++) {
        if (result[i] == 1) {
            printf("S");
        }
        else {
            printf("W");
        }
        //printf("%c", answer[i]);
    }
}

int main () {
    scanf("%d", &n);
    scanf("%s", answer);
    flag = 0;
    result[0] = 1;
    result[n - 1] = 1;
    circulateAnimals();
    check ();
    printResult ();
    if (flag == 2) {
        return 0;
    }
    flag = 0;
    result[0] = -1;
    result[n - 1] = 1;
    circulateAnimals();
    check ();
    printResult ();
    if (flag == 2) {
        return 0;
    }
    flag = 0;
    result[0] = 1;
    result[n - 1] = -1;
    circulateAnimals();
    check ();
    printResult ();
    if (flag == 2) {
        return 0;
    }
    flag = 0;
    result[0] = -1;
    result[n - 1] = -1;
    circulateAnimals();
    check ();
    printResult ();
    if (flag == 2) {
        return 0;
    }
    printf("-1");
}