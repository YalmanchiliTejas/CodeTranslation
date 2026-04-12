#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;
int main(void){
    int N ; 
    cin >> N ;
    int a;
    a = N / 15 ;

    cout << (N * 800) -( a * 200) << endl;
    return 0;
}