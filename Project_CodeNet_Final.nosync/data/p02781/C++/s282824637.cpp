#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string n;
    cin >> n;
    int k;
    cin >> k;
    int i,j;
    int digit = n.size();
    vector<vector<vector<ll>>> dp(digit+1,vector<vector<ll>>(2,vector<ll>(k+1,0)));
    dp.at(0).at(1).at(0) = 1;
    for(i = 0;i < digit;++i){
        for(j = 0;j <= k;++j){
            if(n.at(i) == '0'){
                if(j == 0){
                    dp.at(i+1).at(0).at(j) = dp.at(i).at(0).at(j);
                    dp.at(i+1).at(1).at(j) = dp.at(i).at(1).at(j);
                }else{
                    dp.at(i+1).at(0).at(j) = dp.at(i).at(0).at(j) + dp.at(i).at(0).at(j-1)*9;
                    dp.at(i+1).at(1).at(j) = dp.at(i).at(1).at(j);
                }
            }else{
               if(j == 0){
                    dp.at(i+1).at(0).at(j) = dp.at(i).at(0).at(j) + dp.at(i).at(1).at(j);
                }else{
                    dp.at(i+1).at(0).at(j) = dp.at(i).at(0).at(j) + dp.at(i).at(0).at(j-1)*9 + dp.at(i).at(1).at(j) + dp.at(i).at(1).at(j-1)*(n.at(i) - '0' -1);
                    dp.at(i+1).at(1).at(j) = dp.at(i).at(1).at(j-1);
                }
            }
        }
    }
    cout << dp.at(digit).at(0).at(k) + dp.at(digit).at(1).at(k) << endl;
    return 0;
}