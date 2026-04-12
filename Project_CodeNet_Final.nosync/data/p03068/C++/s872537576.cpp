#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cctype>
#include <bitset>
using namespace std;
int main()
{
    int N,K,i;
    string S;
    cin >> N >> S >> K;
    for(i = 0;i < N;i++){
        if(S[i] != S[K - 1]){
            S[i] = '*';
        }
    }
    cout << S << endl;
}