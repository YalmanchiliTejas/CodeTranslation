#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(void){
    ll h,w;
    cin >> h>> w;
    vector<string>mass;
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        bool flag = false;
        for(int j=0;j<w;j++){
            if(s[j]=='#'){
                flag = true;
                break;
            }
        }
        if(flag == true){
            mass.push_back(s);
        }
    }

    // cout << endl;
    // for(int i=0;i<mass.size();i++){
    //     for(int j=0;j<w;j++){
    //         cout << mass[i][j];
    //     }
    //     cout << endl << endl;
    // }

    vector<bool>flag(w);
    for(int i=0;i<w;i++){
        flag[i]==false;
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<mass.size();j++){
            if(mass[j][i]=='#'){
                flag[i] = true;
                break;
            }
        }
    }

    for(int i=0;i<mass.size();i++){
        for(int j=0;j<w;j++){
            if(flag[j]==true){
                cout << mass[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}