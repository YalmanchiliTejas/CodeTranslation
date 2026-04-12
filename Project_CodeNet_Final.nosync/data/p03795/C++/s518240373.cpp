#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

long int jou(long int x, long int y){
    long int f = 1;
    for(int i = 0; i < y; ++i){
        f = f * x % int(powl(10,9) + 7);
    }

    return f;
}

bool pn(long int x){
    if(x != 2 && x % 2 == 0)
        return false;

    for(int i = 3; i < x; ++i){
        if(x != i && x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    cout << n * 800 - n / 15 * 200 << endl;
    
    return 0;
}