#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int d[300000];
    for(int i=0;i<N;i++){
        cin >> d[i];
    }

    int maxd = 0;
    for(int i=0;i<N-1;i++){
        maxd = (maxd>d[i])?maxd:d[i];
        if(maxd<10){
            cout << "no" << endl;
            return 0;
        }
        maxd -= 10;
    }

    maxd = 0;
    for(int i=N-1;i>0;i--){
        maxd = (maxd>d[i])?maxd:d[i];
        if(maxd<10){
            cout << "no" << endl;
            return 0;
        }
        maxd -= 10;
    }

    cout << "yes" << endl;
    return 0;
} 
