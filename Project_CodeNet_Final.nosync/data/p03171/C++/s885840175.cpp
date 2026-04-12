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

using namespace std;

void cout_vec(vector<long long> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

void cout_mat(vector<vector<long long>> &mat){
    for(int i=0; i<mat.size(); i++){
        vector<long long> vec = mat[i];
        cout_vec(mat[i]);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N,0);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    vector<vector<long long> > dp(N+1,vector<long long>(N+1,0));
    for(int i=1; i<=N; i++){
        for(int j=0; j < N-i+1; j++){
            dp[j][j+i]=max((long long) a[j]-dp[j+1][j+i], (long long) a[j+i-1]-dp[j][j+i-1]);
        }
    }

    //cout_mat(dp);
    cout << dp[0][N] << endl;
}