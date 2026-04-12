//                          VIVEK UPADHYAY
//                         MANIT, BHOPAL(M.P)
/**********************************************************************************************/
/**********************************************************************************************/
//                        $$ JAB-TAK TODEGA NHI,
//                           TAB -TAK CHODEGA NHI :D
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<set>
#include<unordered_map>
#include<cstdio>
#include<map>
#include<numeric>
using namespace std;
#define F first
#define S second
#define mk(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define LINE cout<<endl ;
#define ok cout<<"ok\n" ;
typedef long long ll;
const int MAXN = 1e5 + 10 ;
const int MAX = 1e6 ;
double pi = 3.1415926535897932384626433832795;
const ll inf=1e18 ;
ll mod = 1e9 + 7 ;
int main(){
    int  N ;
    cin >> N ;
    ll a[N] ;
    ll mx = 0 ;
    for(int i=0;i<N;i++)
        cin >> a[i] ;
    sort(a,a+N) ;
    vector<ll> p ;
    int i =1 , j = N-1 ;
    ll st = a[0] , ed = a[0] ;
    ll sum =0 ;
    while(i <= j){
        ll diff1 = max(abs(st-a[j]),abs(ed-a[j])) ;
        ll diff2 =  max(abs(st-a[i]),abs(ed-a[i])) ;
        if(diff1 > diff2){
            sum+=diff1 ;
            if(abs(st-a[j]) > abs(ed-a[j])) st = a[j] ;
            else ed = a[j] ;
            j-- ;
        }
        else {
            sum+=diff2 ;
            if(abs(st-a[i]) > abs(ed-a[i])) st = a[i] ;
            else ed = a[i] ;
            i++ ;
        }
    }
    cout<<sum<<endl;
    return 0 ;
}
