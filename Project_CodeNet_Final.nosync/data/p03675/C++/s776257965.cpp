#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;



int main()
{
    ll N;

    cin >> N;

    ll a[N];

    ll array[512345];

    ll left = 212345;
    ll right = left + 1;
    REP(i,N)
    {
        cin >> a[i];
    }

    REP(i,N)
    {
        if(i % 2 == (N-1)%2)
        {
            array[left--] = a[i];
        }
        else
        {
            array[right++] = a[i];
        }
    }

    for(ll i = left+1; i< right; ++i)
    {
        cout << array[i] << " ";
    }
}

