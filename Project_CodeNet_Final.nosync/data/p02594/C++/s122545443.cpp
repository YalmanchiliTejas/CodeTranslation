/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                       *
 *          Fortis Fortuna Adiuvat                                       * 
 *                          "Fortune Favours the bold"                   *
 *                                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vll vector<int>
#define pb push_back
#define pll pair<int, int>
#define w(t) int t; cin >> t; while(t--)
#define print(x,y) cout << x << " " << y << endl
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define setbits(x) __builtin_popcountll(x)
#define endl "\n"

template <typename T>
void write(vector<T> &a) {        
    for(auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;}
void random(int nMin, int nMax, int n){
    srand(time(0));
    for(int i = 0; i < n; i++){
        double var = nMin + (int)((double)rand() / ((double)RAND_MAX+1) * (nMax-nMin+1));cout << var << " ";}cout << endl;
}
///////////Helper Functions///////////


////////////Main Method///////////////
int32_t main()
{
//////////////////////////////////////////////////////////
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << setprecision(15);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
//////////////////// Code Here ///////////////////////////    
{
    int n;cin >> n;
    if(n >= 30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}    
return 0 ;
}