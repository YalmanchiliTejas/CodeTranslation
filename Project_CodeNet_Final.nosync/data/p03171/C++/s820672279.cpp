#include<iostream>
#include<vector>

using namespace std;

int main() {

    int n;
    cin>>n;
    vector<long long int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<pair<long long int,long long int>>> dp(n, vector<pair<long long int,long long int>>(n));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j += n) {
            dp[i][j] = {v[i], 0};
        }
    }

    for (int c = 1; c < n; c++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + c; j < n; j += n) {

                //cout<< i<<" "<<j<<endl;
                pair<long long int,long long int> p1 = {v[i] + dp[i + 1][j].second, dp[i + 1][j].first};
                pair<long long int,long long int> p2 = {v[j] + dp[i][j - 1].second, dp[i][j - 1].first};

                if (p1.first > p2.first) { dp[i][j] = p1; }
                else dp[i][j] = p2;
            }
        }
    }

//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<'{'<<dp[i][j].first<<':'<<dp[i][j].second<<'}';
//        }
//        cout<<endl;
//    }
//
//    cout<<"ans ";

    cout<<dp[0][n-1].first-dp[0][n-1].second;


    return 0;
}
