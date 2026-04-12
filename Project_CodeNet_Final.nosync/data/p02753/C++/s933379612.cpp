#include <iostream>
using namespace std;

int main(){
    char s;
    cin >> s;
    for(int i=0;i<2;i++){
        char t;
        cin >> t;
        if(t!=s){
            cout << "Yes" << endl;
            break;
        }
        else{
            s = t;
        }

        if(i==1)
            cout << "No" << endl;
    }

    return 0;
}
