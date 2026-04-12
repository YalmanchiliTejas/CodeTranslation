
 #include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);
#define setnow clock_t tStart=clock();
#define time (double)(clock() - tStart)/CLOCKS_PER_SEC;
#define setin(x) ifstream cin(x);
#define setout(x) ofstream cout(x);
typedef long long ll;
typedef long long int lli;
typedef pair < int, int> dbl;
const int maxInt = 1e9*2;
const lli maxLong = 1e18*2;

int main(){
           int n;
           cin >> n;
           int x = n * 800;
           int y = n / 15 * 200;
           cout << x-y<<endl;
}
