#include <iostream>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;   cin >> s;
    int ab[2] = {0};
    rep(i, 3){
        if(s[i] == 'A') ab[0]++;
        else            ab[1]++;
    }
    if(ab[0] && ab[1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
