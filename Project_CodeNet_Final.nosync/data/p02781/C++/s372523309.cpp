#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    int k;
    cin >> N;
    cin >> k;
    vector<vector<int>> data(k+1, vector<int>(2));

    for (int i=0; i < N.size(); i++){
        int n = (int)(N[i] - '0');
        if (i==0){
            data.at(1).at(0) = 1;
            data.at(0).at(1) = 1;
            data.at(1).at(1) = n - 1;

            continue;
        }
        
        for (int j=k; j > 0; j--){
            data.at(j).at(1) += data.at(j-1).at(1)*9;
            if (n != 0){
                data.at(j).at(1) += (n - 1) * data.at(j-1).at(0) + data.at(j).at(0);
                data.at(j).at(0) = data.at(j-1).at(0);
            }
        }

    }
    cout << data.at(k).at(0) + data.at(k).at(1) << endl;

}