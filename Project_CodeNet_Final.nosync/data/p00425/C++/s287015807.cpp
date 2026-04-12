#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
using namespace std;
#define rep(i, j) for(int i = 0; i < j; i++)
#define f(i, k, j) for(int i = k; i < j; i++)
const int INF = (1 << 26);

int main(){
    int n;
    while(cin >>n && n){
        int ans = 1, T = 1, S = 2, E = 3;
        rep(i, n){
            string str; cin >>str;
            if(str == "North"){
                swap(T, S);
                S = 7 - S;
            } else if(str == "East"){
                swap(T, E);
                T = 7 - T;
            } else if(str == "West"){
                swap(T, E);
                E = 7 - E;
            } else if(str == "South"){
                swap(T, S);
                T = 7 - T;
            } else if(str == "Right"){
                swap(E, S);
                E = 7 - E;
            } else if(str == "Left"){
                swap(E, S);
                S = 7 - S;
            }
            ans += T;
        }
        cout <<ans <<endl;
    }
    return 0;
}