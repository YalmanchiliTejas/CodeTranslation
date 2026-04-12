#include <bits/stdc++.h>

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast")
//1.0 * clock() / CLOCKS_PER_SEC

#define fi first
#define se second
#define ll long long int
#define dl double long

using namespace std;

const ll NN = 1e10 + 7;
const int N = 1e5 + 7;
const int M = 11;
const ll mod = 1e9 + 7;

void solve1()
{
	int n;
	cin >> n;
	if(n >= 30)
		cout << "Yes";
	else
		cout << "No";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); srand(time(0));
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );
	//freopen( "moobuzz.in" , "r" , stdin );
    //freopen( "moobuzz.out" , "w" , stdout );
    
    int cghf = 1;//cin >> cghf;
    while( cghf-- ){
        solve1();
    }
}
