#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

long long mod = 1000000007;

int main()
{
    int N;
    long long a[200005];
    long long res = 0;;
    long long sum = 0;
    
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a[i];
        sum += a[i]%(2*mod);
        res += ((a[i]%(2*mod))*(a[i]%(2*mod)))%(2*mod);
        sum = sum%(2*mod);
        res = res%(2*mod);
    }
    
    long long num = (sum*sum)%(2*mod);
    
    if (num >= res){
        cout << ((num - res)%(2*mod))/2 << endl;
    }
    else {
        cout << ((num - res + 2*mod)%(2*mod))/2 << endl;
    }
    
}
