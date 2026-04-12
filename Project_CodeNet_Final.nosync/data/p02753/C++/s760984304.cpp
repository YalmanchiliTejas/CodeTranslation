#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod=1000000007;
#define pb  push_back
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORA(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define count_1(n)  __builtin_popcountll(n)
#define parity(n)   __builtin_parityll(n)   //Even parity 0 as output
void show    (int a[], int arraysize) { for (int i = 0; i < arraysize; ++i)  {cout << a[i] << " ";}	cout<<endl;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
void sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}
int main()
{FAST

string s;
cin>>s;
if(s[0]==s[1]&&s[1]==s[2])
{
	cout<<"No"<<endl;
}
else
cout<<"Yes"<<endl;

return  0;
}


