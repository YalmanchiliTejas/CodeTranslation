#include <iostream>
using namespace std;

int main(){
    int h, w;cin>>h>>w;
    int total = h + w - 1;
    int acc = 0;
    for (int i=0;i<h;i++){
        string temp;
        cin >> temp;
        for (int j=0;j<w;j++){
            if(temp[j] == '#'){
                acc++;
            }
        }
    }
    if(acc == total){
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}