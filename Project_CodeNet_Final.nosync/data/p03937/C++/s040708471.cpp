#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define sz size()
#define en end()
#define ro return 0
#define br break
#define con continue;
#define um unordered_map<ll,ll>
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace2(a,b) cerr <<"a is " << a << " b is " << b << el;
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
char c[12][12];
int main()
{
    ios;
    ll row , col ;
    cin >> row >> col ;
    forn(i , 1 , row)
    {
        forn(j, 1 , col ) {
            cin >> c[i][j]  ;
        }
    }
    ll flag  = -1 ;
    ll cr = 1 , cc = 1;
    while(1){
        if(cr == row and cc == col ) break ;
         ll tr = 0 ,  tb= 0 ;
         forn(i , cc +1 , col){
            if(c[cr][i] == '#') {
                tr ++ ;
            }
         }
         forn(i , cr +1 , row){
             if(c[i][cc] == '#') {
                ++tb;
             }
         }
         if(tr > 0 and tb> 0 ) {
            flag = 0 ;
            br ;
         }
         else if(tr > 0 and tb== 0 ) {
             cr = cr ;
             cc = cc+1 ;
         }
         else if(tr == 0 and tb > 0 ){
            cr = cr +  1;
            cc = cc ;
         }
    }
    if(flag == -1){
        cout <<"Possible\n";
        ro ;
    }
    else cout << "Impossible\n" ;
    ro ;
}
























