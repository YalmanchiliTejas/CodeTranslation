#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a,b) (a += b,b = a - b,a -= b)
#define ll long long

const int MOD = 1e9 + 7;

int main() {
    int a, b, n;
    cin >> n;

    cout << n * 800 - (n / 15) * 200 << endl;

}