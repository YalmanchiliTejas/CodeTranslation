#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    int x[150]={0};

    for (int i=0;i<n;i++){
        cin >>x[i];
    }
    int best=1;
    int tmp=0;
    int flag=x[0];
    for (int j=1;j<n;j++){
        if (x[j]>=flag){
            flag=x[j];
            best++;
        }

    }
    cout <<best <<endl;




    return 0;
}
