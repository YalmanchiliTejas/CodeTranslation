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

const long INF = (1l << 30);
const long LINF = (1l << 60);

char c;
int main(){
    std::cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    printf("vowel\n");
    }else{
    printf("consonant\n");
    }
}