#include <iostream>
using namespace std;
int main(void){
    string str="";
    int flag=0;
    cin >> str;
    for(int i=0;i<2;i++){
        if(str.at(i)!=str.at(i+1)){
            flag=1;
        }
    }
    if(flag==1){
        cout << "Yes" <<endl;
    }
    else
    cout << "No" <<endl;
}
