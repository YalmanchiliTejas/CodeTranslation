#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;

#define max(a,b) a > b ? a : b

int main() {

    int N, M;

    cin >> N >> M;

    if (N == M)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }

    return 0;
}