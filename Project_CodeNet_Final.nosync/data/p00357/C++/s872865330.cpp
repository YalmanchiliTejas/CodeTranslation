#include <iostream>
using namespace std;

int main(){
    int n;  cin >> n;

    int d[n];
    for(int i=0;i<n;i++)    cin >> d[i];

    int x(0);
    for(int i=0;i<n-1;i++){
        if(d[i]<10){
            if(x<=0){
                cout << "no" << endl;
                return 0;
            }
        }

        x--;
        if(x<=d[i]/10-1){
            x = d[i]/10-1;
        }
    }

    x = 0;
    for(int i=n-1;i>0;i--){
        if(d[i]<10){
            if(x<=0){
                cout << "no" << endl;
                return 0;
            }
        }

        x--;
        if(x<=d[i]/10-1){
            x = d[i]/10-1;
        }
    }

    cout << "yes" << endl;
    return 0;
}
