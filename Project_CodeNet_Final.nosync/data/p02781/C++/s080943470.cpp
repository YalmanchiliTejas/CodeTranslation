#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	int k;
    string n;
    cin>>n>>k;
    int m=n.length();
    vector<vector<vector<vector<LL>>>> dp(m+1,vector<vector<vector<LL>>>(10,vector<vector<LL>>(5,vector<LL>(2,0))));
    dp[0][0][0][0]=1;
    LL ans=0;
    cerr<<"init"<<endl;
    FOR(ii,0,m){
        //cerr<<"ii:"<<ii<<endl;
        FOR(jj,0,10){
            FOR(kk,0,4){
                FOR(ll,0,2){
                    int t=dp[ii][jj][kk][ll];
                    if(kk==k&&ll==0&&t!=0){
                        //cerr<<kk<<" "<<t<<endl;
                    }
                    FOR(nx,0,10){
                        int add=nx==0?0:1;
                        int lf=1,nn=n[m-ii-1]-'0';
                        if(nn>nx){
                            lf=0;
                        }else if (nn<nx){
                            lf=1;
                        }else{
                            lf=ll;
                        }
                        dp[ii+1][nx][kk+add][lf]+=t;
                    }
                }
            }
        }
    }
    cerr<<"dp"<<endl;
    FOR(ii,m,m+1){
        FOR(jj,0,10){
            FOR(kk,k,k+1){
                FOR(ll,0,1){
                    int t=dp[ii][jj][kk][ll];
                    //cerr<<jj<<" "<<t<<endl;
                    ans+=t;
                }
            }
        }
    }
    cout<<ans;
    





}
