#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> hvec(h);
    vector<bool> hbool(h,false);
    vector<bool> wbool(w,false);
    for(int i=0;i<h;i++){
        cin >> hvec[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(hvec[i][j] == '#'){
               hbool[i] = true;
               wbool[j] = true;
            }
                
            }
        }
     for(int i=0;i<h;i++){
         if(hbool[i] == true){
        for(int j=0;j<w;j++){
            if(wbool[j] == true){
                cout << hvec[i][j];
            }
            
            
        }
        cout << endl;
     }
     }
    
}
