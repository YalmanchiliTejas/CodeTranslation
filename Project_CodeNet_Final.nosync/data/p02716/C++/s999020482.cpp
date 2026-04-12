#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}
template<typename T>
void cout_mat(vector<vector<T>  > &mat){
    for(int i=0; i<mat.size(); i++){
        vector<T> vec = mat[i];
        cout_vec(mat[i]);
    }
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N,0);
    for(auto &a:A){
        cin >> a;
    }

    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(3,vector<ll>(2,-MOD*MOD)));
    dp[0][0][0]=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            dp[i+1][j][1]=max(dp[i+1][j][1], dp[i][j][0]+A[i]);
            dp[i+1][j][0]=max(dp[i+1][j][0], dp[i][j][1]);

            if(j<2){
                dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][0]);
            }
        }
    }
    //cout_mat(dp[N]);cout << endl;
    if(N%2==0){
        cout << max(dp[N][0][0],max(dp[N][1][1],dp[N][1][0])) << endl;
    }else{
        cout << max(max(dp[N][1][1],dp[N][1][0]), dp[N][2][1]) << endl;
    }
}