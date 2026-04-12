#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define MAXN 11111

const int INF = 1 << 29 ;
typedef long long ll ;
typedef pair < int , int > pii ;

int main() {
    ios::sync_with_stdio(0) ;
    int x , y , z ;
    scanf("%d %d %d" ,&x , &y ,&z) ;
    x-=(2*z + y) ;
    cout << x/(y+z) + 1 << endl ;
    return 0 ;
}