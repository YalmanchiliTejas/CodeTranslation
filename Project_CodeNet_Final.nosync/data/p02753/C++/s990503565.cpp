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

std::string s;
long cnt[2];

int main(){
    std::cin >> s;
    for(int i = 0; i < 3; i++){
        cnt[s[i] - 'A']++;
    }
    if(cnt[0] != 0 && cnt[1] != 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
