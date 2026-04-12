#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<iosfwd>
#include<sstream>
#include<math.h>
#define N 100
using namespace std;

int main(void){
    int n;
    cin >> n;
    int cnt=0;
    vector<int> h(n,0);
    int max= 0;
    for(int i=0; i<n; i++){
        cin >> h[i];
        if(max<=h[i]){
            max= h[i];
            cnt++;
        }
    }
    cout << cnt <<endl;
}