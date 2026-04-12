#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0xfff;
const int maxn = 100005;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n>=30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}