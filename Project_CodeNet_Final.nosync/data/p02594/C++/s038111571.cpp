#include<stdio.h>
#include<iostream>

using namespace std;

int main(void){

    int temperature;
    cin >> temperature;
    // cout << temperature;

    if( temperature >= 30 ){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}