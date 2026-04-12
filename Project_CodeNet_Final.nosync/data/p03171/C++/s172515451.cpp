#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define ALL(x) x.begin(),x.end()
#define LL long long int

int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////////////////////

const int N = 3e3+100;
LL arr[N];
LL dp[N][N];

LL total(LL x,LL y , bool c ){
    // trace(x,y,c);
    if(dp[x][y] != -1LL) return dp[x][y] ;
    if(x > y ) return 0;
    if(c == 0) return  dp[x][y ]=  max( arr[x] + total(x+1,y,!c) , arr[y] + total(x,y-1,!c) );
    else return dp[x][y] =  min(total(x+1,y,!c) -arr[x],total(x,y-1,!c) -arr[y]);
} 


int solve(int x, int y,int c){
    if(x == y){
        return arr[x];
    }
    int mini = min(arr[x] + solve(x+1,y,c^1),arr[y] + solve(x,y-1,c^1));
    int maxi = min(arr[x] + solve(x+1,y,c^1),arr[y] + solve(x,y-1,c^1));

    int play1 = min( arr[x] + solve(x+1,y,1) - solve(x+1,y,0) ,arr[y] +  solve(x,y-1,1) - solve(x,y-1,0) );
    int play2 = min( arr[x] + solve(x+1,y,1) - solve(x+1,y,0) ,arr[y] +  solve(x,y-1,1) - solve(x,y-1,0) );
    if(c == 0){
        return play1;
    }else{
        return play2;
    }
}


int main()
{
    
    LL n;
    cin >> n;
    forn(i,n) forn(j,n) dp[i][j] = -1LL;
    forn(i,n) cin >> arr[i];
    cout << total(0,n-1,0) << endl;
}
