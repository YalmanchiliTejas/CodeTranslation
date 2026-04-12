#include<iostream>
#include<string>
using namespace std;

int unres[10001][100] = {};
int res[10001][100] = {};

int main(){

    string k;
    int d;
    cin >> k;
    cin >> d;

    unres[0][0] = 1;
    res[0][0] = 1;

    for(int i = 1; i <= k.size(); i++){
        for(int j = 0; j < d; j++){
            for(int dig = 0; dig < 10; dig++) unres[i][j] = (unres[i][j] + unres[i-1][(20*d+j-dig)%d])%1000000007;
        }
    }

    for(int i = 1; i <= k.size(); i++){
        for(int j = 0; j < d; j++){
            for(int dig = 0; dig < (k[k.size()-i] - '0'); dig++) res[i][j] = (res[i][j] + unres[i-1][(20*d+j-dig)%d])%1000000007;
            res[i][j] = (res[i][j] + res[i-1][(20*d+j-(k[k.size()-i]-'0'))%d])%1000000007;
        }
    }

    cout << (res[k.size()][0] + 1000000006)%1000000007;

    return 0;
}
