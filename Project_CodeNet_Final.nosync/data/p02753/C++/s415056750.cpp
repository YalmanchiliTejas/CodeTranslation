#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<unordered_set>

using namespace std;




vector<int> prime_sieve(int n)
{
    int* arr = new int[n+1];
    
    int i, p;
    for (i = 0; i <= n; ++i) {
        arr[i] = i;
    }
    for (i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            for (p = arr[i] * arr[i]; p <= n; p += arr[i]) {
                arr[p] = 0;
            }
        }
    }
    vector<int> primes;
    for (i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            primes.push_back(arr[i]);
        }
    }
    return primes;
}

int min(int a, int b)
{
    return a < b ? a : b;
}



int main()
{
    string str;
    cin >> str;
    int i;
    int a = 0, b = 0;
    for (i = 0; i < str.length();++i)
    {
        if (str[i] == 'A') {
            ++a;
        }
        if (str[i] == 'B') {
            ++b;
        }
    }
    if (a == 0 || b == 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    
}

    



