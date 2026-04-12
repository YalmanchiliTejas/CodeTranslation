#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define		fuckshitup  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) // don't use for small inputs
#define		endl		"\n"
#define		ll			long long int
#define		mod			1000000007
#define		f(i,a,b)	for(ll i = (ll)(a); i < (ll)(b); i++)
#define		rf(i,a,b)   for(ll i = (ll)(a); i > (ll)(b); i--)
#define		ull			unsigned long long
#define		ld			long double

struct custom_hash{
    static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};

int main()
{
	fuckshitup;
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2] && s[0] == s[2])
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
}
