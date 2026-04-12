#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
        int H,W;

        cin >> H >> W;
        int i,j;
        vector<string> a(H);

        for(i=0;i<H;i++){
                cin >> a[i];
        }

        vector<bool> row(H,false);
        vector<bool> col(W,false);

        for(i=0;i<H;i++){
                for(j=0;j<W;j++){
                        if(a[i][j]=='#'){
                        row[i]=true;
                        col[j]=true;
                        }
                }
        }

        for(i=0;i<H;i++){
                if(row[i]){
                        for(j=0;j<W;j++){
                                if(col[j]){
                                cout << a[i][j];
                                }
                        }
                cout << endl;
                }
        }

        return 0;
}