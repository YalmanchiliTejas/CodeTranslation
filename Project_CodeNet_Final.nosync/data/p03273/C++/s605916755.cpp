#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int H,W;
    vector<bool> row(H,false);
    vector<bool> col(W,false);

    cin >> H >>W;
    string List[H];
    for (int i = 0;i<H;i++){
        cin >> List[i];
    }
    for (int i =0;i<H;i++){
        for(int j = 0;j<W;j++){
            if (List[i][j]=='#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i=0;i<H;i++){
       if (row[i]){
           for(int j=0;j<W;j++){
               if (col[j]){
                   cout << List[i][j];
               }
           }
            cout<<endl;
       }
    }

}