/*	MASTER HAS FAILED MORE TIMES
	THAN BEGINNER HAS EVER TRIED
*/

#include <bits/stdc++.h>

using namespace std;

#define endl             '\n'
#define all(a)           a.begin(), a.end()
#define mem(a, n)        memset(a, n, sizeof(a))
#define Unique(n)        (n).erase(unique(all(n)), (n).end())
#define NumofDigits(n)   ((long long)log10(n)+1)
#define repeat(i, a, n)  for(int i=a; i<n; i++)
#define isPowerOfTwo(n)  (n && !(n & (n - 1)))

typedef long long ll;
typedef long double ld;

int sieve(int n);
unsigned long long pow(long long base, long long power);
long long gcd(long long a, long long b)
{
    return a%b ? gcd(b, a%b) : b;
}
long long lcm(long long a, long long b)
{
    return a*b/gcd(a, b);
}

void quicken()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void file()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif /*ONLINE_JUDGE*/
}

int main()
{
    quicken();

    string s; cin >> s;
    if(s.substr(0, 2)=="AB" || s.substr(1, 2)=="AB"
       || s.substr(0, 2)=="BA" || s.substr(1, 2)=="BA")
        cout << "Yes";
    else cout << "No";

    return 0;
}

unsigned long long pow(long long base, long long power)  /// mod?
{
    if(power==0)
        return 1;
    if(power==1)
        return base;

    unsigned long long ans = pow(base, power/2); /// mod?
    ans *= ans; /// ((ans%mod)*(ans%mod))%mod;

    if(power&1)
        return ans*base; /// ((ans%mod)*(base%mod))%mod;
    return ans;
}

int sieve(int n)
{
    int c = 0;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = 0;

    for(long long i=2; i*i<=n; i++)
        if(isPrime[i])
            for(long long j=i*2; j<=n; j+=i)
                isPrime[j] = 0;
    repeat(i, 0, n+1)
    if(isPrime[i])
        c++;
    return c; /// primeCount [1:n]
}
