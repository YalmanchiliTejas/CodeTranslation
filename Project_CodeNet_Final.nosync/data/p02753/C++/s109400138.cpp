#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, start, end) for(int i = start; i < (int)(end); ++i)

int main(){
    string s;
    cin >> s;
    bool a = false, b = false;
    for(char c: s){
        if(c == 'A') a = true;
        if(c == 'B') b = true;
    }
    if(a & b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}