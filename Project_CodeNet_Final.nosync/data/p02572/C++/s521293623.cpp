#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll N;

    cin >> N;

    ll A[N];
    ll sum = 0;
    ll modulo = 1000000007;
    ll res = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        sum %= modulo;     //Die Summe begrenzen 
    }

    for (int j = 0; j < N; j++)
    {
        sum -= A[j];
        
        if (sum < 0 ) sum+=modulo; // When the first case of the table is 1000000008 then with % modulo it will 
                                  // be 1 instead of 1000000008 which will make the sum negative so in this case we have to add to the sum the amount that we lost which is 1000000007 


        res += A[j] * sum; // for sure when multiplying the 100000000 with a big numer it will stay supportable since we use long long int as a variable 

        res %= modulo;
    }

    cout << res;

    return 0;
}