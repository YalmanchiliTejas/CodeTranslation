#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a (h ,vector<char>(w));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> a[i][j];
    vector<bool> height (h ,true);
    vector<bool> width (w ,true);

    for(int i=0;i<h;i++){
        bool check=true;
        for(int j=0;j<w;j++){
            if(a[i][j] == '#'){
                check = false;
                break;
            }
        }
        if(check)height[i] = false;
    }
    for(int j=0;j<w;j++){
        bool check=true;
        for(int i=0;i<h;i++){
            if(a[i][j] == '#'){
                check = false;
                break;
            }
        }
        if(check) width[j] = false;
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(height[i] && width[j]) cout << a[i][j];
        }
        if(height[i]) cout << endl;
    }
}