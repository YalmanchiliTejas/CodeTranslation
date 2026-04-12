#include<bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    string s[n+2];
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    vector<ll> rows,col;
    for (int i = 0; i < n; ++i) {
        int c =0 ;
        for (int j = 0; j < m; ++j) {
            if(s[i][j] == '.'){
                c++;
            }
        }
        if(c == m){
            rows.push_back(i);
        }
    }
    sort(rows.begin(), rows.end());
    for (int i = 0; i < m; ++i) {
        int c =0 ;
        for (int j = 0; j < n; ++j) {
            if(s[j][i] == '.'){
                c++;
            }
        }
        if(c == n){
            col.push_back(i);
        }
    }
    string s1[n];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if(!binary_search(rows.begin(), rows.end() , i)){
            s1[j] = s[i];
            j++;
        }
    }
    sort(col.begin(), col.end());
    for (int i = 0; i < j; ++i) {
        for (int k = 0; k < m; ++k) {
            if(!binary_search(col.begin(), col.end() , k)){
                cout << s1[i][k];
            }
        }
        printf("\n");
    }
    return 0;
}