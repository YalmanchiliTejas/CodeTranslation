#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;

uint64_t comb(uint64_t n, uint64_t k)
{
    uint64_t result = 1;
    for(uint64_t i=1; i<=k; i++)
    {
        result *= n--;
        result /= i;
    }
    return result;
}

int counter(int n, int k, int size, string &N)
{
    int result=0, digit=(N[size-n]-'0');
    if(n==0)
    {
        if(k==0) result = 1;
        else result = 0;
    }
    else
    {
        if(k==0) result=1;
        else
        {
            if(digit==0) result = counter(n-1, k, size, N);
            else
            {
                result += pow(9, k)*comb(n-1, k);
                result += (digit-1)*pow(9, k-1)*comb(n-1, k-1);
                result += counter(n-1, k-1, size, N);
            }
        }
    }
    return result;
}

int main()
{
    string N;
    int k;
    cin >> N >> k;
    int len=N.length();

    cout << counter(len, k, len, N) << endl;
    return 0;
}