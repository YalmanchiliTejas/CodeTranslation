#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <queue>
#include <fstream>
#include <iterator> // std::back_inserter
#include <chrono>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <float.h>
#include <cassert>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    cin >> N;

    int a[N];

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    int ans = 0;
    int now = 0;

    for(int i=0; i<N; i++){
        if(a[i] >= now){
            ans += 1;
            now = a[i];
        }
    }

    

    cout << ans;

    return 0;
}
