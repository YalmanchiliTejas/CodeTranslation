#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> g;
    for (int i=0; i<h; i++){
        string s;
        cin >>s;
        g.push_back(s);
    }
    
    int a[h];
    int b[w];
    string h_blank="";
    string w_blank="";
    for (int i=0; i<h; i++){
        h_blank+='.';
        a[i]=0;
    }
    for (int i=0; i<w; i++){
        w_blank+='.';
        b[i]=0;
    }
    for (int i=0; i<h; i++){
        if (g[i]==w_blank){
            a[i]=1;
        }
    }
    
    for (int j=0; j<w; j++){
        string t="";
        for (int i=0; i<h; i++){
            t+=g[i][j];
        }
        if (t==h_blank){
            b[j]=1;
        }
    }

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if ( a[i]==0 && b[j]==0){
                cout << g[i][j];
            }
        }
        if (g[i]!=w_blank){
            cout <<endl;
        }
    }
}