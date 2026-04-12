#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<string> a(n);

    vector<int> b;
    vector<int> c;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '#'){
                b.push_back(j);
                c.push_back(i);
            }
        }
    }

    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < b.size(); j++){
            cout << a[c[i]][b[j]];
        }
        cout << endl;
    }
    

    return 0;
}