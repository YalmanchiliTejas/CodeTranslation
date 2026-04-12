#include <iostream>
using namespace std;
int main (){
    int a,b;
    char aa[11];
    char j;
    cin >> a;
    cin >> aa;
    cin >> b;
    j=aa[b-1];
    for (int i=0;i<=a-1;i++){
        if (aa[i]!=j){
            aa[i]= '*';
        }
    }
    cout << aa;


}