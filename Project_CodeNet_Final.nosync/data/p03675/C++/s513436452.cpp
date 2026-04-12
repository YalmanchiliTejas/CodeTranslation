#include <bits/stdc++.h>
using namespace std;
#define MOD           1000000007
#define forn(i,s,n)   for(int i = s ; i < n ; i++)
#define mp            make_pair
#define pb            push_back  
#define st            first
#define nd            second
#define sz(v)         ((int)((v).size()))
const int SIZE=1000000;
const int OO = (int)1e9;
const double PI = acos(-1);
typedef vector<int> vi;
typedef long long int ll;  
typedef pair<int , int > ii;
typedef pair<int , int > Point;
typedef pair<pair<int, double> , int > iii;
int   C[SIZE+6];
bool f[SIZE+8];

int main(){
     
    int n ;
    vi A;
    scanf("%d" , &n);
    forn(i , 0 , n){
         int q;
         scanf("%d", &q);
         A.pb(q);
         
         
      //    forn(i , 0 , sz(A))printf("%d " , A[i]);
         // cout << endl;
    }
    for(int i = n-1 ; i>=0 ; i-=2)printf("%d " , A[i]);
    int st = 0;
    if(n&1)st=1;
    for(int i = st ; i <n ; i+=2)printf("%d " , A[i]);
 }