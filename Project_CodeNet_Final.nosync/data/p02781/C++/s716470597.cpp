/*
 *  * main.cpp
 *   *
 *    */

#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<cassert>
#include<stdlib.h>
#include<time.h>
using namespace std;

char N[1003];
long long res;

void compute(string restr, int level) {
    if (restr.size() > strlen(N)) return;
    if (level == 0) {
        bool isOk = true;
        for (int i = 0; i < restr.size(); ++i)
            if (restr[i] < N[i]) break;
            else if (restr[i] > N[i]) isOk = false;

        if (isOk) res++;

        return;
    }

    compute(restr + "0", level);

    for (int i = 1; i <= 9; ++i) compute(restr + to_string(i), level - 1);
}
int main() {

    int k;
    scanf("%s %d", N, &k);

    int n = strlen(N);

    long long reminder = pow(9, k);

    for (int i = 1; i <= k; ++i) reminder *= (n - i);
    for (int i = 1; i <= k; ++i) reminder /= i;


    for (int i = 1; i <= 9; ++i) {
        string restr = to_string(i);
        compute(restr, k - 1);
    }

    printf("%lld\n", res + reminder);


    return 0;
}
