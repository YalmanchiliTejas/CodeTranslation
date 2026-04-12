#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<map>
#include<vector>

using namespace std;

int main(){
    int x,n;
    cin >> n;
    int y = n/15;
    if(y !=0){
       cout <<  n*800 - y*200 << endl;
    }else{
        cout << n*800 << endl;
        }
}