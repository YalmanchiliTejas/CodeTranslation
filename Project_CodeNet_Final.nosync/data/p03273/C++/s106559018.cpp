#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    vector<int> wmemo;
    vector<int> hmemo;
    for(int i=0;i<h;i++){
        bool flag=true;
        for(int j=0;j<w;j++){
            if('#'==a[i][j]){
                flag=false;
                break;
            }
        }
        if(flag){
            hmemo.push_back(i);
        }
    }
    for(int i=0;i<w;i++){
        bool flag=true;
        for(int j=0;j<h;j++){
            if('#'==a[j][i]){
                flag=false;
                break;
            }
        }
        if(flag){
            wmemo.push_back(i);
        }
    }
    for(int i=0;i<h;i++){
        if(hmemo.end()!=find(hmemo.begin(),hmemo.end(),i)){
            continue;
        }
        for(int j=0;j<w;j++){
            if(wmemo.end()!=find(wmemo.begin(),wmemo.end(),j)){
                continue;
            }
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}