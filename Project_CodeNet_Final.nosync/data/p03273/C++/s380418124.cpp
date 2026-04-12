#include <iostream>
#include <vector>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w));
    vector<bool>x(h,1);
    vector<bool>y(w,1);

    int cnt=0;

    for(int i=0; i<h; i++){
        cnt = 0;
        for(int j=0; j<w; j++){
            cin >> a[i][j];
            if(a[i][j]=='.'){
                cnt++;
            }else{
                continue;
            }
        }
        if(cnt==w){
            x[i]=0;
        }
    }

    for(int i=0; i<w; i++){
        cnt = 0;
        for(int j=0; j<h; j++){
            if(a[j][i]=='.'){
                cnt++;
            }else{
                continue;
            }
        }
        if(cnt==h){
            y[i]=0;
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(x[i]&&y[j]){
                cout << a[i][j];
            }
        }
        if(x[i]) cout << endl;
    }

    return 0;
}