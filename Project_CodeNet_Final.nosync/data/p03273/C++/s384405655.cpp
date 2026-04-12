#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using ll = long long;
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin >> a[i];
    vector<bool> H(h,false);
    vector<bool> W(w,false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                H[i]=true;
                W[j]=true;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(H[i]&&W[j]){
                cout << a[i][j];
            }
        }
        if(H[i]) cout << endl;
    }
    return 0;
}