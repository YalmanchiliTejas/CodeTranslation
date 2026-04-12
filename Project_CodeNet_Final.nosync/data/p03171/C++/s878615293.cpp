#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int 
#define pb push_back
#define mp make_pair
#define endl "\n"
#define mem(x) memset(x, -1, sizeof(x))
const int MOD = 1e9+7;

template <typename T>
void print(T AA[], int nn){for(int ii=0; ii<nn; ii+=1){cout<<AA[ii]<<" ";}cout<<endl;}
template <typename T> inline void print(T nn){ cout << nn << endl;}
/* ----------------------------------------------------------------------------------- */

const int N = 3005;
int A[N], n, cache[N][N][2];

int fn(int i, int j, int turn){
    if(i>j) return 0;
    int &ans = cache[i][j][turn];
    if(ans!=-1) return ans;
    if(turn == 0){
        ans = max(A[i]+fn(i+1, j, 1), A[j]+fn(i, j-1, 1));
    }
    else{
        ans = min(-A[i]+fn(i+1, j, 0), -A[j]+fn(i, j-1, 0));
    }
    return ans;
}


int32_t main(){

    IOS

    mem(cache);
    cin >> n;
    for(int i=0; i<n; i+=1) cin >> A[i];
    print(fn(0, n-1,0));

    return 0;
}