#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>

using ll = long long;
using namespace std;
#define modmod 1000000007

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,k,n) for(int i=k;i<n;i++)


int main(){
    int n;
    cin >> n;
    string S[n];
    string sortS[n];
    for(int i = 0 ; i < n; i ++){
        cin >> S[i];
        sort(S[i].begin(),S[i].end());
    }

    int mat[n][26]={0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < S[i].length(); j++){
            mat[i][S[i][j]-'a']++;
        }
    }

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    */

    int mini = 50;
    string result = "";
    for(int i = 0; i < 26; i++){
        mini = 50;
        for(int j = 0; j < n; j++){
            if(mini > mat[j][i]){
                mini = mat[j][i];
            }
        }
        for(int k = 0; k < mini; k++){
            result += (char)('a'+i);
        }
    }

    cout << result << endl;

    return 0;
}
