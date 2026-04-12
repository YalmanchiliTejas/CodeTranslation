#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N ;
    int a[N];

    cin >> a[0]; 
    int high = a[0];
    int count = 1 ;
    for( int i = 0; i < N-1 ; i++){
        cin >>  a[i+1];
        if(a[i+1]>=high){
            count++;
            high=a[i+1];
        }

    }

    cout << count <<endl;
    return 0;
}