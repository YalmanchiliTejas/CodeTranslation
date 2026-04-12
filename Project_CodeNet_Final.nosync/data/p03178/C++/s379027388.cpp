/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;
const int M = 1e2+5;

const int mod = 1e9+7;

int n;
string s;
int mem[N][3][M];

int add_self(int & a , int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

//state 0 for equal numbers
//1 for smaller
//2 for bigger

int go(int idx , int sta , int sum){
    if(idx == s.size()){
        return sum == 0 && (sta == 0 || sta == 1);
    }
    if(~mem[idx][sta][sum])
        return mem[idx][sta][sum];
    int ways = (sum == 0) && (idx != 0);
    for(int i = ((idx == 0) ? 1 : 0); i <= 9; i++){
        //if(sta == 1){
         //  add_self(ways , go(idx + 1 , 1 , (sum + i) % n));
        //}
        int new_sta = 0;
        if( (sta == 0 && s[idx] - '0' < i) || sta == 2 ){
            new_sta = 2;
        } else if( (sta == 0 && s[idx] - '0' > i) || sta == 1 ){
            new_sta = 1;
        }
        add_self(ways , go(idx + 1 , new_sta , (sum + i) % n));
    }
    return mem[idx][sta][sum] = ways;
}

int main(){
    cin >> s >> n;
    memset(mem , -1 , sizeof mem);
    cout << go(0 , 0 , 0) << endl;
}
