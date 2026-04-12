#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<climits>
using namespace std;
#define REP(i, j) for(int i = 0; i < j; i++)
#define FOR(i, j, k) for(int i = j; i < k; i++)
#define P pair<int, int>
const int INF = INT_MAX / 2;
const int M = 1010;

int main(){
    int m, n;
    while(cin >>m >>n && (n || m)){
        bool human[M] = {false};
        FOR(i, 1, m + 1) human[i] = true;

        int h = m, now = 1;
        FOR(i, 1, n + 1){
            string str; cin >>str;
            if(h == 1) continue;
            while(!human[now]){
                now++;
                if(now > m) now = 1;
            }
            if(i % 3 == 0 && i % 5 == 0){
                if(str != "FizzBuzz"){
                    human[now] = false;
                    h--;
                }
            } else if(i % 3 == 0){
                if(str != "Fizz"){
                    human[now] = false;
                    h--;
                }
            } else if(i % 5 == 0){
                if(str != "Buzz"){
                    human[now] = false;
                    h--;
                }
            } else{
                int tmpInt = atoi(str.c_str());
                if(tmpInt == 0 || i != tmpInt){
                    human[now] = false;
                    h--;
                }
            }
            now++;
        }
        stringstream ss;
        bool firFlg = true;
        REP(i, m + 1){
            if(human[i]){
                if(firFlg){
                    firFlg = false;
                    ss <<i;
                } else{
                    ss <<" " <<i;
                }
            }
        }
        cout <<ss.str() <<endl;
    }
    return 0;
}