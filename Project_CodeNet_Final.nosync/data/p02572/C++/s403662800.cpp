#include <iostream>

#define ll long long

using namespace std;

const int sizes = 2e5+5;
const ll MOD = 1e9 + 7;

long long norm(long long d){ 
return ((d%MOD)+MOD)%MOD;}

long long Madd (long long x, long long y){
return norm(norm(x) + norm(y));}

long long Msub (long long x, long long y){
return norm(norm(x) - norm(y));}

long long Mmul (long long x, long long y){
return norm(norm(x) * norm(y));}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    ll anw = 0;
    cin >> n;

    long long stores[sizes] = {0}, prefix_sum[sizes] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> stores[i];
        prefix_sum[i] = Madd(stores[i], prefix_sum[i-1]);
    }

    for (int i = 1; i <= n - 1; i++)
    {
        anw = Madd(anw, Mmul(stores[i], prefix_sum[n] - prefix_sum[i]));
    }
    cout << anw << "\n";
}