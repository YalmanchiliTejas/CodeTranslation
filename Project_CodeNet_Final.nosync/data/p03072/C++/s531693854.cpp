#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n,t;
    cin >> n;
    int h[n];
    for(int i = 0;i < n;i++){
        cin >> t;
        h[i] = t;
    }
    int total = 1;
    int a = 0;
    for(int i = 1;i < n;i++){
        a = 0;
        for(int  j= 0;j < i;j++){
            if(h[i] < h[j]){
              a = 1;
              
              break;
            }
        }
        if(a == 0)total++;
    }

    cout << total << endl;
}