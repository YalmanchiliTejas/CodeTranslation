#include <bits/stdc++.h>
#include <string>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Int int_fast64_t

int main()
{
    FAST_IO;
    Int n;
    cin >> n;
    if(n>=30)
        cout << "Yes" << endl;
    else
        cout << "No"  << endl;
    return 0;
}
