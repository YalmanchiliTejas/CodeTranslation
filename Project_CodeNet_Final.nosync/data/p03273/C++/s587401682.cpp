#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> v;
    for(int i = 0; i < n; ++i){
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    int arr[n] = {0}, arr1[m] = {0};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v[i][j] == '#'){
                arr[i] = true;
                arr1[j] = true;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(!arr[i])continue;
        for(int j = 0; j < m; ++j){
            if(arr1[j]){
                cout << v[i][j];
            }
        }
        cout << endl;
    }
    return 0;

}
