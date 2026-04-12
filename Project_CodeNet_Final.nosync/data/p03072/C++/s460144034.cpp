#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;



int main(){
    int n, cnt = 0; 
    cin >> n;
    int h[n];
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(h[i] >= max){
            max = h[i];
            cnt++;
        }
    }
    cout << cnt << endl;

}