#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<utility>
#include<map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define FORR(i,n,m) for(int i=n-1;i>=m;i--)
#define all(in) in.begin(),in.end()
#define ALL(in,K) in,in+K
#define INF 100000000
#define MOD 100000007
#define SIZE 100005
#define PI 	3.14159265358979323846

int main()
{
	cin.tie(0);
   	ios::sync_with_stdio(false);
    ll H,W;
    string a[105];
    cin >> H >> W;
    REP(i,H){
        bool canPlessW = 0;
        cin >> a[i];
        REP(j,W){
            //cout << i << ":" << j << endl;
            //cout << a[i][j] << endl;
            if(a[i][j] == '#'){
                canPlessW = 1;
            }
            //cout << a[i][j] << "::" << canPlessW << endl;
        }
        //cout << canPlessW << endl;
        if(!canPlessW){
            i--;
            H--;
        }
    }

    
    bool canPlessH[105]={0};
    REP(i,W){
        REP(j,H){
            if(a[j][i] == '#'){
                canPlessH[i] = 1;
                break;
            }
        }
        //cout << canPlessH[i] << endl;
    }
    REP(i,H){
        REP(j,W){
            if(canPlessH[j]){
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
