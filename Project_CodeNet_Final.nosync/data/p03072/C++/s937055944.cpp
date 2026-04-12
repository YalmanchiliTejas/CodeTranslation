#include <iostream>
using namespace std;

int main(){
    int aa[20] ,b=1,bb=0,c=0;
    cin>> bb;
    cin >> aa[0];
for (int i=1;i<=bb-1;i++){
    cin >> aa[i];
    for (int j= 0; j<i;j++){
        if(aa[j]>aa[i]  ){
            c=1;
        }
    }
    if(c==0){
        b++;
    }else {
        c=0;
    }
}
cout << b;
}