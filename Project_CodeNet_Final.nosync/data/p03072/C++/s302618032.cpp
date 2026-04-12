#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<stdio.h>
#include<numeric>

using namespace std;

int main(){
    int N, count;
    cin >> N;
    int hmax = 0;
    for (int i = 0; i < N; i++){
        int H;
        cin >> H;
        if (H >= hmax)
            count++;
        hmax = max(hmax, H);
    }
    cout << count << endl;
}