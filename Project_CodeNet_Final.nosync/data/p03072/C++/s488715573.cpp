#include  <iostream>
#include  <stdio.h>
using namespace std;

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

int main(){

    int N_int;
    cin >> N_int;

    int H[N_int];
    for( int ni = 0 ; ni < N_int ; ni++ ){
        cin >> H[ni];
    }

    int ans_int = 0;
    int max = 0;

    for( int ni = 0 ; ni < N_int ; ni++ ){
        if(H[ni] >= max){
            ans_int = ans_int + 1;
            max = H[ni];
        }
    }

    cout << ans_int;
    

}