#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector <char> > a(h,vector<char> (w));
    vector<bool> H(h,false);
    vector<bool> W(w,false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            //cout << i <<j<< endl;
            cin >> a[i][j];
            if(a[i][j] == '#'){
                H[i] = true;
                W[j] = true;
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(H[i]&&W[j]){
                cout << a[i][j];
            }
        }
        if(H[i]){
            cout << endl;
        }
    }
    
    return 0;
}