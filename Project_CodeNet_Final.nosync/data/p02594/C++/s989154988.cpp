/*
sonu_verma1
*/
#include <bits/stdc++.h>
// For policy based data structure
/*#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> */
using namespace std;
/*using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set;*/
 
#define MD 1000000007
#define X first
#define Y second
#define pb push_back
#define debug(val, ch) cout <<val <<ch
#define FOR(i, st, en, ch) for(register int i = (st); i <= (en) ; i += (ch))
#define RFOR(i, st, en, ch) for(register int i = (st); i >= (en) ; i -= (ch))
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
 
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<bool, int> pbi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
/*********************************************************************/
void test(int r)
{
    int n;
    cin>>n;
    if(n>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    

}
/***********************************************************************/
int main()
{
    fast();
    int t=1,r;
    // cin>>t;
    for(r=1;r<=t;r++)
        test(r);
    return 0;
}