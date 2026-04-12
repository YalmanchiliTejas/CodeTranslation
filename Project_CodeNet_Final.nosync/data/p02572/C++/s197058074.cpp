#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
using namespace std;

const unsigned long long BASE = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter != vec.end(); iter++)

unsigned long long a[200001];
unsigned long long sum[200001];

int main()
{
    int n;
    cin >> n;
    FROM_0(i, n)
    {
        cin >> a[i];
    }
    sum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sum[i] = (sum[i + 1] + a[i]) % BASE;
    }
    unsigned long long result = 0;
    FROM_0(i, n - 1)
    {
        result = (result + a[i] * sum[i + 1]) % BASE;
    }
    cout << result % BASE << endl;
    return 0;
}
