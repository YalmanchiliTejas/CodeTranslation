#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
#define endl "\n"
#define SRK ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 1e-6
typedef long long ll;
using namespace std;


int main()
{
    SRK;
    ll n,i,j;
    cin >> n;
    ll sum = 0,x;
    vector <ll> arr;
    ll arr1[n];
    for (i = 0; i < n; i++)
    {
        cin >> x;
        arr1[i] = x;
        arr.push_back(x);
    }
    reverse(arr.begin(),arr.end());
    for (i = 1; i < n; i++)
    {
        arr[i] += arr[i-1];
    }
    for (i = n - 2,j = 0; j < n - 1; i--,j++)
    {
        sum += ((arr1[j] % (1000000000+7)) * (arr[i] % (1000000000+7)) )% (1000000000+7);
    }
    cout << sum % (1000000000+7) << endl;

}
