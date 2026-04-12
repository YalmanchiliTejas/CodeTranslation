#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

char C;

bool flag = false;

char bowels[5] = {'a','i','u','e','o'};

void solve(){
    for(int i = 0; i < 5; i++){
        if(C == bowels[i])
            flag = true;     
    }

    if(flag)
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}

int main(){
    cin >> C;

    solve();
}
