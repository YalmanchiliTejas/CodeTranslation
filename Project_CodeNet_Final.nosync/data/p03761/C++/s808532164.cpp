#include <bits/stdc++.h>
using namespace std;
long int pow107 = (int)pow(10, 9) + 7;
long int limit = LONG_MAX;

bool comp(pair<int, string> a, pair<int, string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

long int jou(long int x, long int y){
    long int f = 1;
    for(int i = 0; i < y; ++i){
        f = f * x % pow107;
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

long int factorial(long int n){
    long int f = 1;
    for(long int i = 1; i <= n; ++i){
        f = f * i % pow107;
    }
    return f;
}

//最大limit
//10^9+7    pow107
//素数pn
//n乗jou
//コンビネーションfactorial
//

int main(){
    vector <string> v;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        v.push_back(s);
    }
    const int h = n;
    int x[h][26] = {};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < v[i].size(); ++j){
            x[i][v[i][j] - 'a']++;
        }
    }
    int min[26] = {};
    for(int i = 0; i < 26; ++i){
        min[i] = x[0][i];
        for(int j = 1; j < v.size(); ++j){
            if(min[i] > x[j][i])
                min[i] = x[j][i];
        }
    }
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < min[i]; ++j){
            cout << char('a' + i);
        }
    }
    cout << endl;

    return 0;
}
