#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int h, w; cin>>h>>w;
    char a[110][110];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }

    int i=0;
    while(i<h){ //yoko
        int sum=0;
        for(int j=0; j<w; j++){
            if(a[i][j] == '.'){
                sum++;
            }
        }

        if(sum == w){
            h--;
            for(int k=i; k<h; k++){
                for(int j=0; j<w; j++){
                    a[k][j] = a[k+1][j];
                }
            }
        }
        else{
            i++;
        }
    }

    i=0;
    while(i<w){
        int sum=0;
        for(int j=0; j<h; j++){
            if(a[j][i] == '.'){
                sum++;
            }
        }

        if(sum == h){
            w--;
            for(int k=i; k<w; k++){
                for(int j=0; j<h; j++){
                    a[j][k] = a[j][k+1];
                }
            }
        }
        else{
            i++;
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}