#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int b[n+1];
    float interval;
    float offset;
    int repeat = 0;
    offset = float(n+1)/2.0;
    if (n%2==0){
        interval = 0.5;
    }else{
        interval = 0.0;
        repeat = 1;
    }
    for (int i=0;i<n;i++){
        if(repeat == 0){
            cin >> b[int(offset+interval)];
        }else{
            cin >> b[int(offset-interval)];
        }
        repeat++;
        if(repeat==2){
            repeat = 0;
            interval += 1.0;
        }
    }
    for (int i=1;i<n;i++){
        cout << b[i] << ' ';
    }
    cout << b[n] << endl;
}
