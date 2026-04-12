//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
 
ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


int r, c;
char arr[10][10];
bool done[10][10];



int main(){

    ios_base::sync_with_stdio(0);

    cin>>r>>c;
    for(int i=0;i<r;i++)
        cin>>arr[i];

    int x = 0, y = 0;
    done[x][y] = true;
    while(1){

        if(x+1<r && !done[x+1][y] && arr[x+1][y] == '#'){
            x++;
            done[x][y] = true;
        }
        else if(y+1<c && !done[x][y+1] && arr[x][y+1] == '#'){
            y++;
            done[x][y] = true;
        }
        else{
            break;
        }
    }
   
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j] == '#' && !done[i][j]){
                cout<<"Impossible";
                return 0;
            }

    cout<<"Possible";
    return 0;
}





