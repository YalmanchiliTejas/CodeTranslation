#include <bits/stdc++.h>
using namespace std;
void program(); int main() {cin.sync_with_stdio(0); cin.tie(0); cin.exceptions(cin.failbit); program();}
#define int long long
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>

#define N 10007
#define D 107
#define MOD 1000000007

int a[N], dp1[N][D], dp2[N][D];

void program(){
    string K;
    cin>>K;
    int n = K.size();

    for(int i=0;i<n;i++)
        a[i] = K[i] - '0';
    int d;
    cin>>d;

    for(int j=0;j<=9;j++) dp1[n-1][j%d] += 1;
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<d;j++){
            //cout << "BLAH" << endl;
            for(int v=0; v<=9; v++) 
            {
                dp1[i][j] = (dp1[i][j] + dp1[i+1][(j-v+9*d)%d])%MOD;
                //cout << dp1[i][j] <<  " " << dp1[i+1][(j-v+d)%d] << " " << (j-v+d)%d << endl;
            }
        }

    for(int j=0;j<=a[n-1];j++) dp2[n-1][j%d] += 1;
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<d;j++) {
            for(int v=0; v<a[i]; v++) 
                dp2[i][j] = (dp2[i][j] + dp1[i+1][(j-v+9*d)%d])%MOD;
            dp2[i][j] = (dp2[i][j] + dp2[i+1][(j-a[i]+9*d)%d])%MOD;
        }
    /*
    cout<<"dp1[i][j]"<<endl;
    for(int j=0;j<d;j++){
        for(int i=0;i<n;i++){
            cout <<"\t"<<dp1[i][j];
        }
        cout<<endl;
    }

    cout<<"dp2[i][j]"<<endl;
    for(int j=0;j<d;j++){
        for(int i=0;i<n;i++){
            cout <<"\t"<<dp2[i][j];
        }
        cout<<endl;
    }
    */

    cout<<(dp2[0][0]-1+MOD)%MOD<<endl;
}

/*
WA:
-bounds on loops
-truncating
-intialization
-0 vs 1 indexing

TLE:
-might need unordered_set/map
-infinite while loop

Stuck:
-different perspective?
-bruteforce?
-greedy?
-reduce dimensionality with problem contraints?
*/
