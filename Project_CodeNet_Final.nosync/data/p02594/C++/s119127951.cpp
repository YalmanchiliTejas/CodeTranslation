#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for(int i=a; i<b; i++)
#define rev(str) reverse(str.begin(), str.end())
#define UPPER(str) transform(str.begin(), str.end(), str.begin(), ::toupper)
#define LOWER(str) transform(str.begin(), str.end(), str.begin(), ::tolower)
#define MOD 1000000007
#define INF 1000000001
#define epsilon 1e-15
typedef long long int ll;
typedef unsigned long long int ull;

#define MAX 100000 
#define init(arr, val) memset(arr, val, sizeof(arr))

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);                                       
    freopen("output.txt", "w", stdout);
    #endif

    int x;
    cin >> x;
    if(x >= 30) cout << "Yes\n";
    else cout << "No\n";



    return 0;
}