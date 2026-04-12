#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)
#define INF 1000000000

int main(void){

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(26));

    roop(i, n){
        string s;
        cin >> s;
        for(int j = 0;s[j] != '\0';j++){
            a[i][s[j]-'a']++;
        }
    }

    roop(i, 26){
        int value = INF;
        roop(j, n){
            value = min(value, a[j][i]);
        }
        roop(j, value) cout << (char)(i+'a');
    }

    cout << endl;

    return 0;
}