#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    string n;
    int ns;
    int k;
    cin >> n;
    cin >> k;

    ns = n.size();
    vector<vector<LL>> dp0(ns+1, vector<LL>(k+1, 0));
    vector<vector<LL>> dp1(ns+1, vector<LL>(k+1, 0));

    dp0[0][0]=1;
    dp1[1][1]=1;

    int tmp;
    for(int i=0; i<ns; i++){
        tmp = n[i]-'0';
        for(int j=0; j<=k; j++){
            if(tmp==0){
                dp0[i+1][j]+=dp0[i][j];
                if(j+1<=k){
                    dp0[i+1][j+1]+=dp0[i][j]*9;
                }
                if(j!=0){
                    dp1[i+1][j]+=dp1[i][j];
                }
            }else{
                dp0[i+1][j]+=dp0[i][j]+dp1[i][j];
                if(i==0 && j==0){
                    dp0[i+1][j+1]+=dp0[i][j]*(tmp-1);
                }else if(j+1<=k){
                    dp0[i+1][j+1]+=dp0[i][j]*9+dp1[i][j]*(tmp-1);
                }
                if(j!=0 && j+1<=k){
                    dp1[i+1][j+1]+=dp1[i][j];
                }
            }
        }
    }

    /*
    cout << "test0" << endl; 

    for(int i=1; i<=ns; i++){
        for(int j=0; j<=k; j++){
            cout << i << " " << j << " " << dp0[i][j] << endl;
        }
    }

    cout << "test1" << endl; 

    for(int i=1; i<=ns; i++){
        for(int j=0; j<=k; j++){
            cout << i << " " << j << " " << dp1[i][j] << endl;
        }
    }
    */
    

    cout << dp0[ns][k]+dp1[ns][k] << endl;

    return 0;
}
