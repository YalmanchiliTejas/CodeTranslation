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
    int N,i,MAX,a;
    cin >> N;
    int H[N];
    for(i = 0;i < N;i++) cin >> H[i];
    a = 1;
    MAX = H[0];
    for(i = 1;i < N;i++){
        if(MAX <= H[i]){
            MAX = H[i];
            a++;
        }
    }
    cout << a << endl;
}