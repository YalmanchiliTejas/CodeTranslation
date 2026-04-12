#include <bits/stdc++.h>
using namespace std;

#define Wingardium_Leviosa ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long int

#define pii pair <int, int>
#define pll pair <ll, ll>

#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pii>
#define vpll vector <pll>

#define mapinrev for(auto i = m.rbegin(); i != m.rend(); i++)

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define line cout << "\n"

const ll mod = 1e9 + 7;

const ll N = 1e6 + 100;
ll pr[N] = {0};

ll SEr()
{   for(ll i = 2; i < N; i++){
        if(pr[i] == 0){
            for(ll j = 2*i; j < N; j += i) pr[j]++;
        }
    } return 0;
}

bool isPrime(ll n)
{
    if(pr[n] == 0) return true;
    else return false;
}

ll power(ll a, ll b){
	a %= mod; ll res = 1;
	while(b > 0)
	{
		if(b % 2) {res *= a; res %= mod;}
		a *= a; a %= mod; b /= 2;
	}
	return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
    	return a ;
	}
    else {
    	return gcd (b , a % b) ;
	}
}

ll lcm(ll a, ll b) {
    return ((a / gcd(a , b)) * b) ;
}

/*
 ____________________________________________________________
|                                                            |
|       I solemnly swear that I am up to no good.            |
|____________________________________________________________|

*/


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    Wingardium_Leviosa;

    ll T = 1;
    //cin >> T;
    while(T--)
    {
        ll n, i;
        cin >> n;
        if(n >= 30)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}

/*
 ____________________________________________________________
|                                                            |
|                   Mischief managed!                        |
|____________________________________________________________|

*/
