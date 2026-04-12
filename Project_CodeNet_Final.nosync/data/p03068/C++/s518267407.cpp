#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
const int mod = 1e9 + 7;
const int INF = 1e9;
using namespace std;
typedef long long ll;

int main()
{
    int n;
    string s;
    int k;
    cin >> n >> s >> k;
    char x = s[k-1];
    for(int i = 0; i < n; i++){
        if(s[i] == x){
            cout << x;
        }else{
            cout << '*';
        }
    }
}
