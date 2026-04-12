#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
string saiki(vector<vector<char>> a,int n,int m,vector<int> c){
    if(c[0] == n-1 && c[1] == m-1){
        if(a[c[0]-1][c[1]] == '#' && a[c[0]][c[1]-1] == '#'){
            return "Impossible";
        }
        else{
        return "Possible";
        }
    }
    else{
        if(c[0] != 0 && c[1] != 0 && a[c[0]-1][c[1]] == '#' && a[c[0]][c[1]-1] == '#'){
            return "Impossible";
        }
        else{
        if(a[c[0] + 1][c[1]] == '#' && a[c[0]][c[1] + 1] != '#'){
            c[0]++;
            return saiki(a,n,m,c);
        }
        else if(a[c[0] + 1][c[1]] != '#' && a[c[0]][c[1] + 1] == '#'){
            c[1]++;
            return saiki(a,n,m,c);
        }
        else{
            return "Impossible";
        }
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a;
    vector<char> b;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            b.push_back('r');
        }
        a.push_back(b);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    vector<int> c = {0,0};
    if(a[0][0] != '#'){
        cout << "Impossible";
    }
    else{
    string ans = saiki(a,n,m,c);
    cout << ans << endl;
    }
}