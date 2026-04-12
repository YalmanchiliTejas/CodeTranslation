#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>
#define _USE_CMATH_DEFINES

const long INF = (1l << 30);
const long LINF = (1l << 60); //1.15*10^18

long n;
std::string s;
long in[100005];
long out[100005];//0:sheep, 1:wolves

int main(){
    scanf("%ld", &n);
    std::cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            in[i] = 0;
        }else{
            in[i] = 1;
        }
    }
    for(int a = 0; a < 4; a++){
        out[0] = a / 2;
        out[1] = a % 2;
        for(int i = 1; i < n-1; i++){
            out[i+1] = (in[i] + out[i] + out[i-1]) % 2;
        }
        if((out[n-1] == (in[0] + out[0] + out[1]) % 2) && (out[0] == (in[n-1] + out[n-1] + out[n-2]) % 2)){
            for(int i = 0; i < n; i++){
                if(out[i] == 0){
                    printf("S");
                }else{
                    printf("W");
                }
            }
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
}
